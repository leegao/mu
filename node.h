#include <iostream>
#include <vector>
#include <string>

class CodeGenContext;
class NStatement;
class NExpression;
class NVariableDeclaration;

typedef std::vector<NStatement*> StatementList;
typedef std::vector<NExpression*> ExpressionList;
typedef std::vector<NVariableDeclaration*> VariableList;

class Node {
public:
    virtual ~Node() {}
    virtual std::string name(){
    	return "Node";
    }
    virtual std::string emit(){
    	return "";
    }
};

class NExpression : public Node {
public:
	virtual std::string name(){
		return "NExpression";
	}
};

class NStatement : public Node {
public:
	virtual std::string name(){
		return "NStatement";
	}
};

class NMatch : public NExpression{
public:
	NExpression& expr;
	ExpressionList patterns;
	NMatch(NExpression& expr, ExpressionList patterns) :
		expr(expr), patterns(patterns){}
};

class MatchPattern : public NExpression{
public:
	NExpression& block;
	ExpressionList patterns;
	MatchPattern(NExpression* pattern, NExpression& block) :
		block(block) {patterns.push_back(pattern);}
};

class NListElements : public NExpression{
public:
	ExpressionList elements;
	NListElements(ExpressionList& elements) : elements(elements){}
	std::string name(){
		return "NListStatement";
	}
};

class NNumber : public NExpression {
public:
    double value;
    NNumber(double value) : value(value) { }
};

class NInlineCond : public NExpression {
public:
	NExpression cond, valid, invalid;
	NInlineCond(NExpression& cond, NExpression& valid, NExpression& invalid) :
		cond(cond), valid(valid), invalid(invalid) { }
};

class NBoolean : public NExpression {
public:
	bool value;
	NBoolean(bool value) : value(value){}
};

class NIdentifier : public NExpression {
public:
    std::string name;
    NIdentifier(const std::string& name) : name(name) { }
};

class NMethodCall : public NExpression {
public:
    NExpression& id;
    ExpressionList arguments;
    NMethodCall(NExpression& id, ExpressionList& arguments) :
        id(id), arguments(arguments) { }
    NMethodCall(NExpression& id) : id(id) { }
};

class NListIndex : public NExpression {
public:
	NExpression& list, index;
	NListIndex(NExpression& list, NExpression& index) :
		list(list), index(index) {}
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression& lhs;
    NExpression& rhs;
    NBinaryOperator(NExpression& lhs, int op, NExpression& rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
};

class NAssignment : public NExpression {
public:
    NIdentifier& lhs;
    NExpression& rhs;
    NAssignment(NIdentifier& lhs, NExpression& rhs) :
        lhs(lhs), rhs(rhs) { }
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }
};

class NDoNothing : public NExpression {

};

class NNegation : public NExpression {
public:
	NExpression& expr;
	NNegation(NExpression& expr) :
		expr(expr){}
};

class NNot : public NExpression {
public:
	NExpression& expr;
	NNot(NExpression& expr) :
		expr(expr){}
};

class NString : public NExpression {
public:
	std::string str;
	bool regex;
	NString(std::string str);
	void process();
};

class NNewIndex : public NStatement {
public:
	NExpression& list, index, value;
	NNewIndex(NExpression& list, NExpression& index, NExpression& value) :
		list(list), index(index), value(value) {}
};

class NNil : public NExpression {
public:
	NNil(){}
};

class NExpressionStatement : public NStatement {
public:
    NExpression& expression;
    NExpressionStatement(NExpression& expression) :
        expression(expression) { }
};

class NBreak : public NStatement {

};

class NReturn : public NStatement {
public:
	NExpression& return_expr;
	NReturn(NExpression& return_expr) :
		return_expr(return_expr){}
};

class NVariableDeclaration : public NStatement {
public:
    NIdentifier& id;
    NExpression *assignmentExpr;
    NVariableDeclaration(NIdentifier& id) :
        id(id) { }
    NVariableDeclaration(NIdentifier& id, NExpression *assignmentExpr) :
        id(id), assignmentExpr(assignmentExpr) { }
};

class NFunctionDeclaration : public NExpression {
public:
    VariableList arguments;
    NBlock& block;
    NFunctionDeclaration(const VariableList& arguments, NBlock& block) :
        arguments(arguments), block(block) { }
};

class NWhileLoop : public NStatement {
public:
    NExpression& cond;
    NBlock& block;
    NWhileLoop(NExpression& cond, NBlock& block) :
        cond(cond), block(block) { }
};

class ForCounter{};
class InCounter : public ForCounter{
public:
	NIdentifier& variable;
	NExpression& iterable;
	InCounter(NIdentifier& variable,
		NExpression& iterable) :
		variable(variable), iterable(iterable) {}
};

class LoopCounter : public ForCounter{
public:
	NExpression& pre, cond, counter;
	LoopCounter(NExpression& pre,
		NExpression& cond, NExpression& counter) :
			pre(pre), cond(cond), counter(counter) {}
};

class VarLoopCounter : public ForCounter{
public:
	NStatement& pre;
	NExpression& cond, counter;
	VarLoopCounter(NStatement& pre,
		NExpression& cond, NExpression& counter) :
			pre(pre), cond(cond), counter(counter) {}
};

class NForLoop : public NStatement {
public:
	ForCounter& counter;
	NBlock& block;
	NForLoop(ForCounter& counter, NBlock& block) :
		counter(counter), block(block) {}
};

class NIf : public NStatement {
public:
	NExpression& cond;
	NBlock& block, else_;
	NIf(NExpression& cond, NBlock& block, NBlock& else_) :
		cond(cond), block(block), else_(else_) {}
	void else_if(NExpression& cond, NBlock& block);
	void else_end(NBlock& block);
};
