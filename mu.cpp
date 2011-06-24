/*
 * mu.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: lee
 */

#include <iostream>
#include "node.h"

extern NBlock* programBlock;
extern int yyparse();

int main(int argc, char** argv){
	yyparse();
	std::cout << programBlock << std::endl;
	return 0;
}
