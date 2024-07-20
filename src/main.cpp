#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include <util/util.h>

#include <parser/ast.h>

#include <lexer/lexer.h>

static inline std::string readFileToString(const std::string& filePath) {
	// Create an input file stream
	std::ifstream file(filePath);

	// Check if the file opened successfully
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return "";
	}

	// Create a stringstream to hold the file contents
	std::stringstream buffer;
	buffer << file.rdbuf();

	// Return the contents as a string
	return buffer.str();
}

#define OUTPUT_TOKEN_CASE(in) case TokenType::in: std::cout << #in << std::endl; break;

int main(int argc, char* argv[])
{
	Lexer lexer;

	std::vector<Token> tokens = lexer.lex(readFileToString("C:/Users/Pasha/source/github-repos/C++ Preproceser/examples/test.lx"));

	std::cout << "Tokens(" << tokens.size() << ") :" << '\n';

	for (Token& token : tokens)
	{

		try
		{
			std::cout << "KEYWORD: " << Lexer::keywords[token.type] << std::endl;
		}

		catch (std::out_of_range)
		{
			if (token.type == TokenType::IDENTIFIER)
				std::cout << "IDENTIFIER : " << token.value << std::endl;
				
			else
			{
				switch (token.type)
				{
					OUTPUT_TOKEN_CASE(PLUS)
					OUTPUT_TOKEN_CASE(MINUS)
					OUTPUT_TOKEN_CASE(MULTIPLY)
					OUTPUT_TOKEN_CASE(DIVIDE)
					OUTPUT_TOKEN_CASE(MODULO)

					OUTPUT_TOKEN_CASE(PLUS_EQUALS)
					OUTPUT_TOKEN_CASE(MINUS_EQUALS)
					OUTPUT_TOKEN_CASE(MULTIPLY_EQUALS)
					OUTPUT_TOKEN_CASE(DIVIDE_EQUALS)
					OUTPUT_TOKEN_CASE(POWER)
					OUTPUT_TOKEN_CASE(ROOT)

					OUTPUT_TOKEN_CASE(EQUALS)
					OUTPUT_TOKEN_CASE(LESS_THAN)
					OUTPUT_TOKEN_CASE(GREATER_THAN)
					OUTPUT_TOKEN_CASE(LESS_THAN_EQUALS)
					OUTPUT_TOKEN_CASE(GREATER_THAN_EQUALS)
					OUTPUT_TOKEN_CASE(NOT_EQUALS)

					OUTPUT_TOKEN_CASE(ASSIGN)

					OUTPUT_TOKEN_CASE(LEFT_PAREN)
					OUTPUT_TOKEN_CASE(RIGHT_PAREN)

					OUTPUT_TOKEN_CASE(LEFT_BRACE)
					OUTPUT_TOKEN_CASE(RIGHT_BRACE)

					OUTPUT_TOKEN_CASE(LEFT_BRACKET)
					OUTPUT_TOKEN_CASE(RIGHT_BRACKET)

					OUTPUT_TOKEN_CASE(COMMA)
					OUTPUT_TOKEN_CASE(DOT)
					OUTPUT_TOKEN_CASE(SEMICOLON)
					OUTPUT_TOKEN_CASE(COLON)
					OUTPUT_TOKEN_CASE(DOUBLE_COLON)
					OUTPUT_TOKEN_CASE(ARROW)
					OUTPUT_TOKEN_CASE(DOUBLE_ARROW)
				}
			}
		}
	}

	return 0;
}