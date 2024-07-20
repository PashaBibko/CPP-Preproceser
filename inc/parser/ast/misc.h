#pragma once

struct ASTIdentifier : public Node
{
	ASTIdentifier() { this->type = NodeType::AST_IDENTIFIER; }

	std::string name;
};

struct Scope : public Node
{
	std::vector<std::unique_ptr<Node>> instructions;
};

struct FunctionAST : public Scope
{
	FunctionAST() { this->type = NodeType::FUNCTION; }

	std::string name;

	bool isInline = false;
};

struct MathmaticalOperation : public Node
{
	MathmaticalOperation() { this->type = NodeType::MATHMATIC_OPERATION; }

	std::vector<std::unique_ptr<Node>> operands;
};