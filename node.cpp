/*
 * node.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: lee
 */

#include "node.h"
#include <sstream>
#include "parser.hpp"

using namespace std;

NString::NString(std::string str_){
	// invariant: at least 2 characters
	regex = false;
	if (str_[0] == 'r'){
		str_ = str_.substr(1);
		regex = true;
	}
	str = str_.substr(1, str_.length()-2);
	process();
}

void NString::process(){
	if (regex) return; // good enough
}

void NIf::else_if(NExpression* cond, NBlock* block){
	if (else_->statements.empty()){
		// If else block is empty, then we just push a new if back
		else_->statements.push_back((new NIf(cond, block, (new NBlock()))));
		return;
	}
	NIf* next;
	if (else_->statements.size() == 1 && (next = dynamic_cast<NIf*>(else_->statements.front()))){
		// If else block contains a single if statement, call its else_if too
		next->else_if(cond, block);
	}
}

void NIf::else_end(NBlock* block){
	if (else_->statements.empty()){
		// If else block is empty, then we just push this block
		else_ = block;
		return;
	}
	NIf* next;
	if (else_->statements.size() == 1 && (next = dynamic_cast<NIf*>(else_->statements.front()))){
		// If else block contains a single if statement, call its else_end too
		next->else_end(block);
	}
}

string NMatch::toString(){
	string match = "match " + expr->toString() + " with\n";
	ExpressionList::iterator pattern;
	for (pattern = patterns.begin(); pattern < patterns.end(); pattern++){
		match += (*pattern)->toString() + "\n";
	}
	return match + "\n";
}

string MatchPattern::toString(){
	string match = "";
	ExpressionList::iterator pattern;
	for (pattern = patterns.begin(); pattern < patterns.end(); pattern++){
		match +=  (pattern == patterns.begin() ? "  " : "| ") + (*pattern)->toString() + "\n";
	}
	return match + block->toString() + "\n";
}

string NList::toString(){
	string match = "[";
	ExpressionList::iterator el;
	for (el = elements.begin(); el < elements.end(); el++){
		match +=  (el == elements.begin() ? "" : ", ") + (*el)->toString();
	}
	return match + "]";
}

string NNumber::toString(){
	stringstream ret;
	ret << value;
	return ret.str();
}

string NInlineCond::toString(){
	std::string ret = "";
	ret += cond->toString() + " ? " + valid->toString() + " : " + invalid->toString();
	return ret;
}

string NBoolean::toString(){
	return value ? "true" : "false";
}

string NIdentifier::toString(){
	return id;
}

string NMethodCall::toString(){
	std::string ret = id->toString() + "(";
	ExpressionList::iterator arg;
	for (arg = arguments.begin(); arg < arguments.end(); arg++){
		ret += (arg == arguments.begin() ? "" : ", ") + (*arg)->toString();
	}
	return ret+")";
}

string NListIndex::toString(){
	std::string ret = list->toString();
	return ret + "[" + index->toString() + "]";
}

string NBinaryOperator::toString(){
	std::string ret = lhs->toString() + " ";
	switch(op){
	case TCEQ:
		ret += "==";
		break;
	case TCNE:
		ret += "!=";
		break;
	case TCLT:
		ret += "<";
		break;
	case TCLE:
		ret += "<=";
		break;
	case TCGT:
		ret += ">";
		break;
	case TCGE:
		ret += ">=";
		break;
	case TPLUS:
		ret += "+";
		break;
	case TMINUS:
		ret += "-";
		break;
	case TMUL:
		ret += "*";
		break;
	case TDIV:
		ret += "/";
		break;
	case TAND:
		ret += "and";
		break;
	case TOR:
		ret += "or";
		break;
	case TBITAND:
		ret += "&";
		break;
	case TBITOR:
		ret += "|";
		break;
	case TBITXOR:
		ret += "^";
		break;
	case TCAT:
		ret += "..";
		break;
	case TMOD:
		ret += "%";
		break;
	case TPREPEND:
		ret += "::";
		break;
	case TEXP:
		ret += "**";
		break;
	}
	return ret + " " + rhs->toString();
}

string NAssignment::toString(){
	std::string ret = lhs->toString();
	return ret + " = " + rhs->toString();
}

string NBlock::toString(){
	std::string ret = "{\n";
	StatementList::iterator stmt;
	for (stmt = statements.begin(); stmt < statements.end(); stmt++){
		ret += (*stmt)->toString() + "\n";
	}
	return ret+"}";
}

string NNegation::toString(){
	std::string ret = "-";
	return ret + expr->toString();
}

string NNot::toString(){
	std::string ret = "(not ";
	return ret + expr->toString()+")";
}

string NString::toString(){
	std::string ret = (regex?"r":"");
	ret += "\"" + str + "\"";
	return ret;
}

string NNewIndex::toString(){
	std::string ret = list->toString();
	return ret + "["+index->toString() + "] = " + value->toString() + ";";
}

string NReturn::toString(){
	std::string ret = "return ";
	return ret + return_expr->toString() + ";";
}

string NVariableDeclaration::toString(){
	std::string ret = "var ";
	return ret + id->toString() + " = " + assignmentExpr->toString() + ";";
}

string NFunctionDeclaration::toString(){
	std::string ret = "function(";
	ExpressionList::iterator arg;
	for (arg = arguments.begin(); arg < arguments.end(); arg++){
		ret += (arg == arguments.begin() ? "" : ", ") + (*arg)->toString();
	}
	return ret+") "+block->toString();
}

string NWhileLoop::toString(){
	std::string ret = "while ";
	return ret+cond->toString()+ " " + block->toString();
}
