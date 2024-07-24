#pragma once

#include <vector>
#include <memory>
#include <string>

enum class NodeType : unsigned short
{
	AST_IDENTIFIER,
	
	// Variable declarations (base is a VarDeclaration (abstract))
	// ArethmeticVariableDeclaration is also abstract
	INT_DECLARATION,
	FLOAT_DECLARATION,
	CHAR_DECLARATION,
	BOOL_DECLARATION,
	VOID_DECLARATION,
	STRING_DECLARATION,

	UNKNOWN_TYPE_DECLARATION,

	// Functions
	FUNCTION,

	// Mathmatical operations
	MATHMATIC_OPERATION,

	// Loops
	WHILE_LOOP,
	FOR_LOOP,
	FOR_RANGE_LOOP,

	// If statements
	IF_STATEMENT, // Can be used as an elif
	ELSE_STATEMENT,
	
	// Undefined (helps catch errors)
	UNDEFINED
};

struct Node
{
	protected:
		const NodeType type;

		Node(NodeType type) : type(type) {}

	public:
		Node() : type(NodeType::UNDEFINED) {}
};

struct FakeNode : public Node
{
	FakeNode() : Node(NodeType::UNDEFINED) {}
};

#include <parser/ast/misc.h>

#include <parser/ast/control-flow.h>
#include <parser/ast/declaration.h>

struct FunctionAST : public Scope
{
	FunctionAST() : Scope(NodeType::FUNCTION) {}

	std::string name;

	UnknownTypeDeclaration outputType;

	std::vector<UnknownTypeDeclaration> arguments;

	bool isInline = false;
};

struct FileAST
{
	std::vector<FunctionAST> functions;
};