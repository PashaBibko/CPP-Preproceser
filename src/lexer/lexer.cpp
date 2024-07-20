#include <lexer/lexer.h>

#include <lexer/token.h>

#include <stdexcept>
#include <iostream>

#include <Util/trans-table.h>

static constexpr bool isWhitespace(const char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

static constexpr bool isAlphaNumeric(const char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

Token Lexer::lexMultiChar()
{
	//
	Token out;

	// The length of the word
	size_t lengthOfWord = 1;

	// Loops through the source code until the whitespace is reached
	while (currentIndex + lengthOfWord < currentSource.length() && isAlphaNumeric(currentSource[currentIndex + lengthOfWord]))
		lengthOfWord++;

	// Turns the word into a string
	const std::string word = currentSource.substr(currentIndex, lengthOfWord);

	TokenType tokenType = TokenType::UNDEFINED;

	try
	{
		tokenType = keywords[word];
	}

	catch (std::out_of_range)
	{
		tokenType = TokenType::IDENTIFIER;
		out.value = word;
	}

	out.type = tokenType;

	currentIndex = currentIndex + lengthOfWord - 1;

	return out;
}

std::vector<Token> Lexer::lex(const std::string& input)
{
	std::vector<Token> tokens;

	// The current source code (passed by reference for performance)
	currentSource = input;

	// Sets lexer variables to their default values
	currentIndex = 0;

	currentLine = 1;
	currentIndexOfLine = 1;

	const size_t sourceLength = currentSource.length();

	// Loops through the source code until the end is reached
	while (currentIndex < sourceLength)
	{
		//  Gets the current character
		const char currentChar = currentSource[currentIndex];

		// Checks if the next character is whitespace
		bool isNextCharWhitespace = false;

		size_t nextIndex = currentIndex + 1;

		if (nextIndex < sourceLength)
			isNextCharWhitespace = isWhitespace(currentSource[nextIndex]);

		// Switch statement for the current character
		switch (currentChar)
		{
			// Skips whitespace
			case '\n':
				currentLine++;
				currentIndexOfLine = 1;
				break;

			case ' ':
			case '\t':
			case '\r':
				break;

			// Single character tokens
			// These tokens do not matter if the next character is not whitespace
			case ';':
				tokens.push_back(Token(TokenType::SEMICOLON));
				break;

			case ',':
				tokens.push_back(Token(TokenType::COMMA));
				break;

			case '.':
				tokens.push_back(Token(TokenType::DOT));
				break;

			case '%':
				tokens.push_back(Token(TokenType::MODULO));
				break;

			// Brackets
			// Why are there three different types of brackets?
			case '(':
				tokens.push_back(Token(TokenType::LEFT_PAREN));
				break;

			case ')':
				tokens.push_back(Token(TokenType::RIGHT_PAREN));
				break;

			case '{':
				tokens.push_back(Token(TokenType::LEFT_BRACE));
				break;
				
			case '}':
				tokens.push_back(Token(TokenType::RIGHT_BRACE));
				break;

			case '[':
				tokens.push_back(Token(TokenType::LEFT_BRACKET));
				break;

			case ']':
				tokens.push_back(Token(TokenType::RIGHT_BRACKET));
				break;

			// Single character tokens that matter if the next character is whitespace
			case '+':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::PLUS) : lexPlusOperator());
				break;

			case '-':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::MINUS) : lexMinusOperator());
				break;

			case '*':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::MULTIPLY) : lexMultiplyOperator());
				break;

			case '/':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::DIVIDE) : lexDivideOperator());
				break;

			case '=':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::ASSIGN) : lexEqaulsOperator());
				break;

			case '!':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::NOT) : lexNotOperator());
				break;

			case '<':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::LESS_THAN) : lexLessThanOperator());
				break;

			case '>':
				tokens.push_back(isNextCharWhitespace ? Token(TokenType::GREATER_THAN) : lexGreaterThanOperator());
				break;

			default:
				tokens.push_back(lexMultiChar());
				break;
		}

		// Increments the current index
		currentIndex++;
	}

	return std::move(tokens);
}