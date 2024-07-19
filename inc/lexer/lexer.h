#pragma once

#include <lexer/token.h>

#include <stdexcept>

#include <Util/trans-table.h>

static std::string emptyString = "";

class Lexer
{
	private:
		std::string& currentSource;

		size_t currentIndex;

		size_t currentLine;
		size_t currentIndexOfLine;

		// Operator Functions defined in lexer/operator.cpp

		Token lexPlusOperator();
		Token lexMinusOperator();
		Token lexMultiplyOperator();
		Token lexDivideOperator();
		Token lexEqaulsOperator();
		Token lexNotOperator();
		Token lexLessThanOperator();
		Token lexGreaterThanOperator();
		Token lexColonOperator();

		// Multi-character operators

		Token lexMultiChar();

	public:
		static const TransTable<std::string, TokenType> keywords;

		Lexer() : currentSource(emptyString) {}

		std::vector<Token> lex(const std::string& input);
};