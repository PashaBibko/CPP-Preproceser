#pragma once

#include <lexer/token.h>

#include <stdexcept>

#include <Util/trans-table.h>

class Lexer
{
	private:
		const std::string* currentSource;

		size_t currentIndex = 0;

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

		Lexer() = default;

		std::vector<Token> lex(const std::string& input);
};