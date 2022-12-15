#include "Scan.h"

string isReserved(string s) {
    map<string, string> reserved;
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

queue<Token> string_parse(string tiny) {
    string scannedChar = "";
    queue<Token> scanned;
    Token token;

    for (int i = 0; i < (int) tiny.length(); i++) {
        if (isalpha(tiny[i])) {
            while (isalpha(tiny[i])) {
                scannedChar += tiny[i];
                i++;
            }
            i--;
            token.value = scannedChar;
            if (!isReserved(scannedChar).empty()) {
                token.type = isReserved(scannedChar);
            }
            else {
                token.type = "IDENTIFIER";
            }
            scannedChar = "";
            scanned.push(token);
        }
        else if (isdigit(tiny[i])) {
            while (isdigit(tiny[i])) {
                scannedChar += tiny[i];
                i++;
            }
            i--;
            token.value = scannedChar;
            token.type = "NUMBER";
            scannedChar = "";
            scanned.push(token);
        }
        else if (isspace(tiny[i])) {
            continue;
        }
        else if (tiny[i] == '{') {
            while (i != (int) tiny.length() && tiny[i] != '}') {
                i++;
            }
            if (i == (int) tiny.length()) {
                queue<Token> error;
                Token msg;
                msg.type = "Error";
                msg.value = "Missing closing comment bracket";
                error.push(msg);
                return error;
            }
        }
        else if (tiny[i] == ':' && tiny[i + 1] == '=') {
            token.value = ":=";
            token.type = "ASSIGN";
            scanned.push(token);
            i++;
        }
        else if (tiny[i] == '+') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "PLUS";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '-') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "MINUS";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '/') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "DIV";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '*') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "MULT";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '=') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "EQUAL";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '<') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "LESSTHAN";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == '(') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "OPENBRACKET";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == ')') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "CLOSEDBRACKET";
            scanned.push(token);
            scannedChar = "";
        }
        else if (tiny[i] == ';') {
            scannedChar += tiny[i];
            token.value = scannedChar;
            token.type = "SEMICOLON";
            scanned.push(token);
            scannedChar = "";
        }
    }
    return scanned;
}

void fileOut(queue<Token> s) {
    ofstream myfile;
    myfile.open("Scanner_Output.txt");
    while (!s.empty()) {
        myfile << s.front().type << ", " << s.front().value << "\n";
        s.pop();
    }
    myfile.close();
}

queue<Token> scanFile(string file_contents) {
    queue<Token> scanned;
    scanned = string_parse(file_contents);
    fileOut(scanned);
    return scanned;
}

std::string Scanner_scan(const string &tiny)
{
    queue<Token> all_tokens = scanFile(tiny);
    string res = "";
    while (!all_tokens.empty()) {
        res += all_tokens.front().type + ", " + all_tokens.front().value + "\n";
        all_tokens.pop();
    }
    return res;
}
