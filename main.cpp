#include"scanner.hpp"
#include "config.hpp"
int main(void){

    std::queue<TokenType> All_Tokens;
    std::string tine_language;
    std::string input_file_path="input.txt";
    std::string output_file_path="output.txt";
    tine_language=Scanner_ReadFile(input_file_path);
    All_Tokens = Scanner_get_all_tokens(tine_language);
    Scanner_WriteFile(All_Tokens,output_file_path);

    return EXIT_SUCCESS;
}