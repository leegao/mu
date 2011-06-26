/*
 * type.h
 *
 *  Created on: Jun 25, 2011
 *      Author: lee
 */

#ifndef TYPE_H_
#define TYPE_H_

#include "hashmap.h"

#define TNIL 0
#define TNUM 1
#define TBOOL 2
#define TSTR 3
#define TLIST 4
#define TFUN 5

// internal type
#define TBLOCK 6

typedef struct mu_type{
	char tid;
	union {
		char b;
		short s;
		int i;
		float number;
		char* str;
		struct {
			struct mu_type* lst;
			int size;
		} list;
		struct {
			void* code;
			void* parent;
			int nargs;
			char** args;
		} fun;
		struct {
			void* parent;
			map_t upvalues;
			char** variables;
			struct mu_type* constants;
			map_t locals;
			char* code;
		} code;
		void* ptr;
	} data;
} mu_type;

typedef struct mu_list {
	mu_type* list;
	int size;
} mu_list;

typedef struct block{
	struct block* parent;
	map_t upvalues;
	char** variables;
	mu_type* constants;
	map_t locals;
	char* code;
} block;

typedef struct mu_func {
	block* code;
	block* parent;
	int nargs;
	char** args;
} mu_func;

#endif /* TYPE_H_ */
