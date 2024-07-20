#pragma once

// Abstract
struct Loop : public Scope
{
	std::unique_ptr<MathmaticalOperation> condition;
};

struct WhileLoop : public Loop
{
	WhileLoop() { this->type = NodeType::WHILE_LOOP; }
};

struct ForLoop : public Loop
{
	ForLoop() { this->type = NodeType::FOR_LOOP; }

	std::unique_ptr<Node> initialization;
	std::unique_ptr<Node> increment;
};

struct ForRangeLoop : public Loop
{
	ForRangeLoop() { this->type = NodeType::FOR_RANGE_LOOP; }

	std::unique_ptr<Node> incrementer;
	std::unique_ptr<Node> range;
};

struct ElseStatement : public Scope
{
	ElseStatement() { this->type = NodeType::ELSE_STATEMENT; }
};

struct IfStatement : public Scope
{
	IfStatement() { this->type = NodeType::IF_STATEMENT; }

	std::unique_ptr<MathmaticalOperation> condition;
	std::unique_ptr<IfStatement> next;

	bool hasElse = false;
};