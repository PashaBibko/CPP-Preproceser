#pragma once

struct ASTIdentifier : public Node
{
	ASTIdentifier() : Node(NodeType::AST_IDENTIFIER) {}

	std::string name;
};

// Abstract
struct Scope : public Node
{
	protected:
		Scope(NodeType type) : Node(type) {}
	
	public:
		std::vector<std::unique_ptr<Node>> instructions;

		Scope() : Node(NodeType::UNDEFINED) {}
};

struct MathmaticalOperation : public Node
{
	MathmaticalOperation() : Node(NodeType::MATHMATIC_OPERATION) {}

	std::vector<std::unique_ptr<Node>> operands;
};