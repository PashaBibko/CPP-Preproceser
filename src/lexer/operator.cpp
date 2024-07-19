#include <lexer/lexer.h>

#include <lexer/token.h>

#include <Util/trans-table.h>

Token Lexer::lexPlusOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: ++, +=
	switch (nextChar)
	{
		case '+':
			return Token(TokenType::INCREMENT);

		case '=':
			return Token(TokenType::PLUS_EQUALS);

		default:
			return Token(TokenType::PLUS);
	}
}

Token Lexer::lexMinusOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: --, -=, ->
	switch (nextChar)
	{
		case '-':
			return Token(TokenType::DECREMENT);

		case '=':
			return Token(TokenType::MINUS_EQUALS);

		case '>':
			return Token(TokenType::ARROW);

		default:
			return Token(TokenType::MINUS);
	}
}

Token Lexer::lexMultiplyOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: *= **
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::MULTIPLY_EQUALS);

		case '*':
			return Token(TokenType::POWER);

		default:
			return Token(TokenType::MULTIPLY);
	}
}

Token Lexer::lexDivideOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: /=, //
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::DIVIDE_EQUALS);

		case '/':
			return Token(TokenType::ROOT);

		default:
			return Token(TokenType::DIVIDE);
	}
}

Token Lexer::lexEqaulsOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: ==, =>
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::EQUALS);

		case '>':
			return Token(TokenType::DOUBLE_ARROW);

		default:
			return Token(TokenType::ASSIGN);
	}
}

Token Lexer::lexNotOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: !=
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::NOT_EQUALS);

		default:
			return Token(TokenType::NOT);
	}
}

Token Lexer::lexLessThanOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: <=
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::LESS_THAN_EQUALS);

		default:
			return Token(TokenType::LESS_THAN);
	}
}

Token Lexer::lexGreaterThanOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: >=
	switch (nextChar)
	{
		case '=':
			return Token(TokenType::GREATER_THAN_EQUALS);

		default:
			return Token(TokenType::GREATER_THAN);
	}
}

Token Lexer::lexColonOperator()
{
	const char nextChar = currentSource[currentIndex + 1];

	// Possible operators: ::
	switch (nextChar)
	{
		case ':':
			return Token(TokenType::DOUBLE_COLON);

		default:
			return Token(TokenType::COLON);
	}
}