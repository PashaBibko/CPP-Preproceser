#include <lexer/lexer.h>

#include <lexer/token.h>

#include <Util/trans-table.h>

const TransTable<std::string, TokenType> Lexer::keywords
({
	// Basic types

	{ "int", TokenType::INT },
	{ "char", TokenType::CHAR },
	{ "bool", TokenType::BOOL },
	{ "void", TokenType::VOID },
	{ "float", TokenType::FLOAT },
	{ "string", TokenType::STRING },

	// Control flow
	{ "if", TokenType::IF },
	{ "else", TokenType::ELSE },

	{ "for", TokenType::FOR },
	{ "while", TokenType::WHILE },

	{ "break", TokenType::BREAK },
	{ "continue", TokenType::CONTINUE },
	{ "return", TokenType::RETURN },

	{ "func", TokenType::FUNCTION },
	{ "proc", TokenType::PROCEDURE },

	// Logical
	{ "&&", TokenType::AND },
	{ "and", TokenType::AND },

	{ "||", TokenType::OR },
	{ "or", TokenType::OR },

	{ "not", TokenType::NOT }
});