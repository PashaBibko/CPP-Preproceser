#pragma once

// Abstract
struct VarDeclaration : public Node
{
	protected:
		VarDeclaration(NodeType type) : Node(type) {}

	public:
		std::string name;

		bool constant = false;
		bool reference = false;

		std::unique_ptr<Node> value;

		VarDeclaration() : Node(NodeType::UNDEFINED) {}
};

// Abstract
struct ArethmeticVariableDeclaration : public VarDeclaration
{
	protected:
		ArethmeticVariableDeclaration(NodeType type) : VarDeclaration(type) {}

	public:
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

		ArethmeticVariableDeclaration() : VarDeclaration(NodeType::UNDEFINED) {}
};

struct UnknownTypeDeclaration : public VarDeclaration
{
	std::string typeIdentifier;

	std::vector<std::string> flags;

	UnknownTypeDeclaration() : VarDeclaration(NodeType::UNKNOWN_TYPE_DECLARATION) {}
};

struct IntDeclaration : public ArethmeticVariableDeclaration
{
	IntDeclaration() : ArethmeticVariableDeclaration(NodeType::INT_DECLARATION) {}
};

struct FloatDeclaration : public ArethmeticVariableDeclaration
{
	FloatDeclaration() : ArethmeticVariableDeclaration(NodeType::FLOAT_DECLARATION) {}
};

struct CharDeclaration : public VarDeclaration
{
	CharDeclaration() : VarDeclaration(NodeType::CHAR_DECLARATION) {}

	bool isSigned = true;
};

struct BoolDeclaration : public VarDeclaration
{
	BoolDeclaration() : VarDeclaration(NodeType::BOOL_DECLARATION) {}
};

struct VoidDeclaration : public VarDeclaration
{
	VoidDeclaration() : VarDeclaration(NodeType::VOID_DECLARATION) {}
};

struct StringDeclaration : public VarDeclaration
{
	StringDeclaration() : VarDeclaration(NodeType::STRING_DECLARATION) {}
};