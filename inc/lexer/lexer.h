#pragma once

#include <lexer/token.h>

#include <stdexcept>

#include <Util/trans-table.h>

class Lexer
{
	private:
		// Current source code being lexed
		const std::string* currentSource;

		// Current index in the source code
		size_t currentIndex = 0;

		// Operator Functions defined in lexer/operator.cpp
		// Seperate functions for each operator for higher efficiency

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
		// Translation table for keywords
		static const TransTable<std::string, TokenType> keywords;

		Lexer() : currentSource(nullptr) {}

		std::vector<Token> lex(const std::string& input);
};