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

    virtual std::string toString(){
    	return name();
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
	NExpression* expr;
	ExpressionList patterns;
	NMatch(NExpression* expr, ExpressionList patterns) :
		expr(expr), patterns(patterns){}
	std::string name(){
		return "NMatch";
	}
	std::string toString();
};

class MatchPattern : public NExpression{
public:
	NExpression* block;
	ExpressionList patterns;
	MatchPattern(NExpression* pattern, NExpression* block) :
		block(block) {patterns.push_back(pattern);}
	std::string name(){
		return "MatchPattern";
	}
	std::string toString();
};

class NList : public NExpression{
public:
	ExpressionList elements;
	NList(ExpressionList& elements) : elements(elements){}
	std::string name(){
		return "NList";
	}
	std::string toString();
};

class NNumber : public NExpression {
public:
    double value;
    NNumber(double value) : value(value) { }
	std::string name(){
		return "NNumber";
	}
	std::string toString();
};

class NInlineCond : public NExpression {
public:
	NExpression *cond, *valid, *invalid;
	NInlineCond(NExpression* cond, NExpression* valid, NExpression* invalid) :
		cond(cond), valid(valid), invalid(invalid) { }
	std::string name(){
		return "NInlineCond";
	}
	std::string toString();
};

class NBoolean : public NExpression {
public:
	bool value;
	NBoolean(bool value) : value(value){}
	std::string name(){
		return "NBoolean";
	}
	std::string toString();
};

class NIdentifier : public NExpression {
public:
    std::string id;
    NIdentifier(const std::string& id) : id(id) { }
	std::string name(){
		return "NIdentifier";
	}
	std::string toString();
};

class NMethodCall : public NExpression {
public:
    NExpression* id;
    ExpressionList arguments;
    NMethodCall(NExpression* id, ExpressionList& arguments) :
        id(id), arguments(arguments) { }
    NMethodCall(NExpression* id) : id(id) { }
	std::string name(){
		return "NMethodCall";
	}
	std::string toString();
};

class NListIndex : public NExpression {
public:
	NExpression* list, *index;
	NListIndex(NExpression* list, NExpression* index) :
		list(list), index(index) {}
	std::string name(){
		return "NListIndex";
	}
	std::string toString();
};

class NBinaryOperator : public NExpression {
public:
    int op;
    NExpression* lhs;
    NExpression* rhs;
    NBinaryOperator(NExpression* lhs, int op, NExpression* rhs) :
        lhs(lhs), rhs(rhs), op(op) { }
	std::string name(){
		return "NBinaryOperator";
	}
	std::string toString();
};

class NAssignment : public NExpression {
public:
    NIdentifier* lhs;
    NExpression* rhs;
    NAssignment(NIdentifier* lhs, NExpression* rhs) :
        lhs(lhs), rhs(rhs) { }
	std::string name(){
		return "NAssignment";
	}
	std::string toString();
};

class NBlock : public NExpression {
public:
    StatementList statements;
    NBlock() { }
	std::string name(){
		return "NBlock";
	}
	std::string toString();
};

class NNegation : public NExpression {
public:
	NExpression* expr;
	NNegation(NExpression* expr) :
		expr(expr){}
	std::string name(){
		return "NNegation";
	}
	std::string toString();
};

class NNot : public NExpression {
public:
	NExpression* expr;
	NNot(NExpression* expr) :
		expr(expr){}
	std::string name(){
		return "NNot";
	}
	std::string toString();
};

class NString : public NExpression {
public:
	std::string str;
	bool regex;
	NString(std::string str);
	void process();
	std::string name(){
		return "NString";
	}
	std::string toString();
};

class NNewIndex : public NStatement {
public:
	NExpression* list, *index, *value;
	NNewIndex(NExpression* list, NExpression* index, NExpression* value) :
		list(list), index(index), value(value) {}
	std::string name(){
		return "NNewIndex";
	}
	std::string toString();
};

class NNil : public NExpression {
public:
	NNil(){}
	std::string name(){
		return "NNil";
	}
	std::string toString(){
		return "nil";
	}
};

class NExpressionStatement : public NStatement {
public:
    NExpression* expression;
    NExpressionStatement(NExpression* expression) :
        expression(expression) { }
	std::string name(){
		return "NExpressionStatement";
	}
	std::string toString(){
		return expression->toString() + ";";
	}
};

class NBreak : public NStatement {
public:
	std::string name(){
		return "NBreak";
	}
	std::string toString(){
		return "break;";
	}
};

class NReturn : public NStatement {
public:
	NExpression* return_expr;
	NReturn(NExpression* return_expr) :
		return_expr(return_expr){}
	NReturn(){
		return_expr = new NNil();
	}
	std::string name(){
		return "NReturn";
	}
	std::string toString();
};

class NVariableDeclaration : public NStatement {
public:
    NIdentifier* id;
    NExpression *assignmentExpr;
    NVariableDeclaration(NIdentifier* id) :
        id(id) { }
    NVariableDeclaration(NIdentifier* id, NExpression *assignmentExpr) :
        id(id), assignmentExpr(assignmentExpr) { }
	std::string name(){
		return "NVariableDeclaration";
	}
	std::string toString();
};

class NFunctionDeclaration : public NExpression {
public:
    ExpressionList arguments;
    NBlock* block;
    NFunctionDeclaration(const ExpressionList& arguments, NBlock* block) :
        arguments(arguments), block(block) { }
	std::string name(){
		return "NFunctionDeclaration";
	}
};

class NWhileLoop : public NStatement {
public:
    NExpression* cond;
    NBlock* block;
    NWhileLoop(NExpression* cond, NBlock* block) :
        cond(cond), block(block) { }
	std::string name(){
		return "NWhileLoop";
	}
};

class ForCounter{};
class InCounter : public ForCounter{
public:
	NIdentifier* variable;
	NExpression* iterable;
	InCounter(NIdentifier* variable,
		NExpression* iterable) :
		variable(variable), iterable(iterable) {}
};

class LoopCounter : public ForCounter{
public:
	NExpression* pre, *cond, *counter;
	LoopCounter(NExpression* pre,
		NExpression* cond, NExpression* counter) :
			pre(pre), cond(cond), counter(counter) {}
};

class VarLoopCounter : public ForCounter{
public:
	NStatement* pre;
	NExpression* cond, *counter;
	VarLoopCounter(NStatement* pre,
		NExpression* cond, NExpression* counter) :
			pre(pre), cond(cond), counter(counter) {}
};

class NForLoop : public NStatement {
public:
	ForCounter* counter;
	NBlock* block;
	NForLoop(ForCounter* counter, NBlock* block) :
		counter(counter), block(block) {}
	std::string name(){
		return "NForLoop";
	}
};

class NIf : public NStatement {
public:
	NExpression* cond;
	NBlock* block, *else_;
	NIf(NExpression* cond, NBlock* block, NBlock* else_) :
		cond(cond), block(block), else_(else_) {}
	void else_if(NExpression* cond, NBlock* block);
	void else_end(NBlock* block);
	std::string name(){
		return "NIf";
	}
};
