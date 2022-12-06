#include "scanner.hpp"
#include "config.hpp"

static std::string Scanner_is_special_Char(char c) {
    std::map<char, std::string> reserved;
    reserved['+'] = "PLUS";
    reserved['-'] = "MINUS";
    reserved['*'] = "MULT";
    reserved['/'] = "DIV";
    reserved['='] = "EQUAL";
    reserved['<'] = "LESSTHAN";
    reserved['('] = "OPENBRACKET";
    reserved[')'] = "CLOSEDBRACKET";
    reserved[';'] = "SEMICOLON";
    return reserved[c];
}
static std::string Scanner_is_Reserved_Word(std::string s) {
    std::map<std::string, std::string> reserved;
    reserved["if"] = "IF";
    reserved["then"] = "THEN";
    reserved["else"] = "ELSE";
    reserved["end"] = "END";
    reserved["repeat"] = "REPEAT";
    reserved["until"] = "UNTIL";
    reserved["read"] = "READ";
    reserved["write"] = "WRITE";
    return reserved[s];
}

std::queue<TokenType> Scanner_Scanning(std::string tiny_language) {
    std::queue<TokenType> all_tokens;
    TokenType token;
    std::string scannedChar = "";

    for (int i = 0; i < tiny_language.length(); i++) {
        if (tiny_language[i] == '{') {//no need to push it in tokens
            while (tiny_language[i] != '}') {
                i++;
            }
        }
        else if (!Scanner_is_special_Char(tiny_language[i]).empty()) {
            scannedChar += tiny_language[i];
            token.Token_value = scannedChar;
            token.Token_type = Scanner_is_special_Char(tiny_language[i]);
            all_tokens.push(token);
            scannedChar = "";
        }
        else if (tiny_language[i] == ':' && tiny_language[i + 1] == '=') {
            token.Token_value = ":=";
            token.Token_type = "ASSIGN";
            all_tokens.push(token);
            i++;
        }
        else if (isalpha(tiny_language[i])) {
            while (isalpha(tiny_language[i])) {
                scannedChar += tiny_language[i];
                i++;
            }
            i--;
            token.Token_value = scannedChar;
            if (!Scanner_is_Reserved_Word(scannedChar).empty()) {
                token.Token_type = Scanner_is_Reserved_Word(scannedChar);
            }
            else {
                token.Token_type = "IDENTIFIER";
            }
            scannedChar = "";
            all_tokens.push(token);
        }
        else if (isdigit(tiny_language[i])) {
            while (isdigit(tiny_language[i])) {
                scannedChar += tiny_language[i];
                i++;
            }
            i--;
            token.Token_value = scannedChar;
            token.Token_type = "NUMBER";
            scannedChar = "";
            all_tokens.push(token);
        }
        else if (isspace(tiny_language[i])) {
            continue;
        }

    }
    return all_tokens;
}

std::string Scanner_ReadFile(std::string path) {
    std::string result;
    std::ifstream File_handler(path);
    if (!File_handler.is_open()) {
        std::cout << "error while opening the file - '" << path << "'\n";
        exit(EXIT_FAILURE);
    }
   if(File_handler) {
      std::ostringstream ss;
      ss << File_handler.rdbuf(); 
      result = ss.str();
   }
#if (DEBUG_ENABLE == DEBUG_INFO_ENABLE)
    std::cout<<"\n";
    std::cout<<result<<"\n";
#endif
   return result;
}

void Scanner_WriteFile(std::queue<TokenType> Tokens,std::string filepath) {
    std::ofstream filehandler;
    filehandler.open(filepath);
    while (!Tokens.empty()) {
        filehandler << Tokens.front().Token_type << ", " << Tokens.front().Token_value << "\n";
        Tokens.pop();
    }
    filehandler.close();
}

std::queue<TokenType> Scanner_get_all_tokens(std::string tiny_language ) {
    
    std::queue<TokenType> all_Tokens;
    all_Tokens = Scanner_Scanning(tiny_language);
#if (DEBUG_ENABLE == DEBUG_INFO_ENABLE)
    std::queue<TokenType> debug_use_tokens=all_Tokens;
    std::cout<<"\n";
    while (!debug_use_tokens.empty())
    { 
        std::cout<<debug_use_tokens.front().Token_value<<" , "<< debug_use_tokens.front().Token_type <<"\n";
        debug_use_tokens.pop();
    }
#endif
    return all_Tokens;
}