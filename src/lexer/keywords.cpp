#include <lexer/lexer.h>

#include <lexer/token.h>

#include <Util/trans-table.h>

const TransTable<std::string, TokenType> Lexer::keywords
({
	// Basic types

	{ "int", TokenType::INT },
	{ "float", TokenType::FLOAT },
	{ "double", TokenType::DOUBLE },
	{ "char", TokenType::CHAR },
	{ "bool", TokenType::BOOL },
	{ "void", TokenType::VOID },

	// Control flow
	{ "if", TokenType::IF },
	{ "else", TokenType::ELSE },

	{ "for", TokenType::FOR },
	{ "while", TokenType::WHILE },

	{ "switch", TokenType::SWITCH },
	{ "type_switch", TokenType::TYPE_SWITCH },

	{ "case", TokenType::CASE },
	{ "default", TokenType::DEFAULT },

	{ "break", TokenType::BREAK },
	{ "continue", TokenType::CONTINUE },
	{ "return", TokenType::RETURN },

	// Maths
	{ "+=", TokenType::PLUS_EQUALS },
	{ "-=", TokenType::MINUS_EQUALS },
	{ "*=", TokenType::MULTIPLY_EQUALS },
	{ "/=", TokenType::DIVIDE_EQUALS },

	{ "++", TokenType::INCREMENT },
	{ "--", TokenType::DECREMENT },

	{ "==", TokenType::EQUALS },
	{ "!=", TokenType::NOT_EQUALS },
	{ ">", TokenType::GREATER_THAN },
	{ "<", TokenType::LESS_THAN },
	{ ">=", TokenType::GREATER_THAN_EQUALS },
	{ "<=", TokenType::LESS_THAN_EQUALS },

	{ "&&", TokenType::AND },
	{ "and", TokenType::AND },

	{ "||", TokenType::OR },
	{ "or", TokenType::OR },

	{ "not", TokenType::NOT }
});