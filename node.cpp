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
