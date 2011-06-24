/*
 * node.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: lee
 */

#include "node.h"

using namespace std;

NString::NString(std::string str_){
	// invariant: at least 2 characters
	raw = false;
	if (str_[0] == 'r'){
		str_ = str_.substr(1);
		raw = true;
	}
	str = str_.substr(1, str_.length()-2);
	process();
	//cout << str << " " << raw << endl;
}

void NString::process(){
	if (raw) return; // good enough
}

void NIf::else_if(NExpression& cond, NBlock& block){
	if (else_.statements.empty()){
		// If else block is empty, then we just push a new if back
		else_.statements.push_back((new NIf(cond, block, *(new NBlock()))));
		return;
	}
	NIf* next;
	if (else_.statements.size() == 1 && (next = dynamic_cast<NIf*>(else_.statements.front()))){
		// If else block contains a single if statement, call its else_if too
		next->else_if(cond, block);
	}
}

void NIf::else_end(NBlock& block){
	if (else_.statements.empty()){
		// If else block is empty, then we just push this block
		else_ = block;
		return;
	}
	NIf* next;
	if (else_.statements.size() == 1 && (next = dynamic_cast<NIf*>(else_.statements.front()))){
		// If else block contains a single if statement, call its else_end too
		next->else_end(block);
	}
}
