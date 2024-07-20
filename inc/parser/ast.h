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

	// Functions
	FUNCTION,

	// Mathmatical operations
	MATHMATIC_OPERATION,

	// Loops
	WHILE_LOOP,
	FOR_LOOP,
	FOR_RANGE_LOOP,
	
	// Undefined (helps catch errors)
	UNDEFINED
};

struct Node
{
	protected: NodeType type;
};

#include <parser/ast/misc.h>

#include <parser/ast/control-flow.h>
#include <parser/ast/declaration.h>

struct FileAST
{
	std::vector<FunctionAST> functions;
};