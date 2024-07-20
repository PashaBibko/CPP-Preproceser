#pragma once

// Abstract
struct VarDeclaration : public Node
{
	ASTIdentifier name;

	bool constant = false;
	bool reference = false;

	std::unique_ptr<Node> value;
};

// Abstract
struct ArethmeticVariableDeclaration : public VarDeclaration
{
	enum class Size : unsigned char
	{
		SMALL,
		NORMAL,
		LARGE,

		// Only for integers
		LARGE_LARGE
	};

	Size size = Size::NORMAL;

	bool isSigned = true;
};

struct IntDeclaration : public ArethmeticVariableDeclaration
{
	IntDeclaration() { this->type = NodeType::INT_DECLARATION; }
};

struct FloatDeclaration : public ArethmeticVariableDeclaration
{
	FloatDeclaration() { this->type = NodeType::FLOAT_DECLARATION; }
};

struct CharDeclaration : public VarDeclaration
{
	CharDeclaration() { this->type = NodeType::CHAR_DECLARATION; }

	bool isSigned = true;
};

struct BoolDeclaration : public VarDeclaration
{
	BoolDeclaration() { this->type = NodeType::BOOL_DECLARATION; }
};

struct VoidDeclaration : public VarDeclaration
{
	VoidDeclaration() { this->type = NodeType::VOID_DECLARATION; }
};

struct StringDeclaration : public VarDeclaration
{
	StringDeclaration() { this->type = NodeType::STRING_DECLARATION; }
};