/*
 * mu.cpp
 *
 *  Created on: Jun 23, 2011
 *      Author: lee
 */

#include <iostream>
#include "node.h"
#include "type.h"

extern NBlock* programBlock;
extern int yyparse();

int main(int argc, char** argv){
	std::cout << programBlock << std::endl;
	while(1){
		std::cout << ">> ";
		int i = yyparse();
		std::cout << std::endl;

		NStatement* last = programBlock->statements.back();
		std::cout << last->toString() << std::endl;
	}

	return 0;
}
