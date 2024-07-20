#pragma once

#include <string>

enum class TokenType : unsigned short
{
	// Identifiers //
	IDENTIFIER,

	// Basic types //
	INT,
	CHAR,
	BOOL,
	VOID,
	FLOAT,
	STRING,

	// Control flow //

	// Simple control flow
	IF,
	ELIF,
	ELSE,

	// Loops
	FOR,
	WHILE,

	// Goto statements
	BREAK,
	CONTINUE,
	RETURN,

	// Functions
	FUNCTION,
	PROCEDURE,

	// Operators //

	// Simple arithmetic operators
	PLUS,
	MINUS,
	MULTIPLY,
	DIVIDE,
	MODULO,

	// Complex arithmetic operators
	PLUS_EQUALS,
	MINUS_EQUALS,
	MULTIPLY_EQUALS,
	DIVIDE_EQUALS,

	POWER,
	ROOT,

	// Increment and decrement operators
	INCREMENT,
	DECREMENT,

	// Comparison operators
	EQUALS,
	NOT_EQUALS,

	GREATER_THAN,
	GREATER_THAN_EQUALS,

	LESS_THAN,
	LESS_THAN_EQUALS,

	// Logical operators
	AND,
	OR,
	NOT,

	// Assignment operators
	ASSIGN,

	// Separators //
	
	// Singlechar
	COMMA,
	SEMICOLON,
	COLON,
	DOT,

	// Multichar
	ARROW, // ->
	DOUBLE_ARROW, // =>
	DOUBLE_COLON, // ::

	// Brackets //

	// ()
	LEFT_PAREN,
	RIGHT_PAREN,

	// {}
	LEFT_BRACE,
	RIGHT_BRACE,

	// []
	LEFT_BRACKET,
	RIGHT_BRACKET,

	// Causes an error if not defined
	UNDEFINED
};

class Token
{
	public:
		Token() = default;
		Token(TokenType type, const std::string value = "") : value(value), type(type) {}

		std::string value;
		TokenType type = TokenType::UNDEFINED;
};