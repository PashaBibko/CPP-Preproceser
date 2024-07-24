#pragma once

// Abstract
struct Loop : public Scope
{
	protected:
		Loop(NodeType type) : Scope(type) {}

	public:
		std::unique_ptr<MathmaticalOperation> condition;

		Loop() : Scope(NodeType::UNDEFINED) {}
};

struct WhileLoop : public Loop
{
	WhileLoop() : Loop(NodeType::WHILE_LOOP) {}
};

struct ForLoop : public Loop
{
	ForLoop() : Loop(NodeType::FOR_LOOP) {}

	std::unique_ptr<Node> initialization;
	std::unique_ptr<Node> increment;
};

struct ForRangeLoop : public Loop
{
	ForRangeLoop() : Loop(NodeType::FOR_RANGE_LOOP) {}

	std::unique_ptr<Node> incrementer;
	std::unique_ptr<Node> range;
};

struct ElseStatement : public Scope
{
	ElseStatement() : Scope(NodeType::ELSE_STATEMENT) {}
};

struct IfStatement : public Scope
{
	IfStatement() : Scope(NodeType::IF_STATEMENT) {}

	std::unique_ptr<MathmaticalOperation> condition;
	std::unique_ptr<IfStatement> next;

	bool hasElse = false;
};