/*
 * opcode.h
 *
 *  Created on: Jun 25, 2011
 *      Author: lee
 */

#ifndef OPCODE_H_
#define OPCODE_H_

enum opcodes{
	NOP,
	POP, ROT2, ROT3, ROT4,
	DUP, DUPX,
	NEG, NOT,
	MUL, DIV, MOD, ADD, SUB, EXP,
	AND, OR,
	INDEX, STORE_INDEX,
	BREAK, RETURN,
	BUILD_LIST, PREPEND, APPEND,
	LOAD, STORE, LOAD_CONST,
	PUSH_BLOCK, POP_BLOCK,
	CMP, JMP, JE, JNE, JMPABS,
	MAKE_FUN, CALL
};

#endif /* OPCODE_H_ */
