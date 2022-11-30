#ifndef _SCANNER_H_
#define _SCANNER_H_

#include <iostream>
#include <string>
#include <vector>
#include <cctype>   
#include <fstream>
#include <sstream>
#include <queue>
#include <map>

struct TokenType
{
    std::string Token_type;
    std::string Token_value;
};

std::queue<TokenType> Scanner_Scanning(std::string tiny_language);

std::string Scanner_ReadFile(std::string path);

void Scanner_WriteFile(std::queue<TokenType> Tokens,std::string filepath);

std::queue<TokenType> Scanner_get_all_tokens(std::string tiny_language);

#endif  /*_SCANNER_H_*/