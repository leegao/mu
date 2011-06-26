/*
 * type.h
 *
 *  Created on: Jun 25, 2011
 *      Author: lee
 */

#ifndef TYPE_H_
#define TYPE_H_

#include <vector>
#include <deque>
#include <map>
#include <list>

using namespace std;

#define TNIL 0
#define TNUM 1
#define TBOOL 2
#define TSTR 3
#define TLIST 4
#define TFUN 5

// internal type
#define TBLOCK 6


class MuType{
public:
	static const char tid = 0;
};

class TNil : MuType{
public:
	static const char tid = TNIL;
};

class TNumber : MuType{
public:
	static const char tid = TNUM;
	float value;
	TNumber(float value) :
		value(value) {}
};

class TBool : MuType{
public:
	static const char tid = TBOOL;
	bool value;
	TBool(bool value) :
		value(value) {}
};

class TString : MuType{
public:
	static const char tid = TSTR;
	string value;
	TString(string value) :
		value(value) {}
};

class TList : MuType{
public:
	static const char tid = TLIST;
	deque<MuType*> list;
	TList(deque<MuType*>  list) :
		list(list) {}
	void prepend(MuType* obj){
		list.push_front(obj);
	}
	void append(MuType* obj){
		list.push_back(obj);
	}
	MuType* at(size_t index){
		return list.at(index);
	}
	void assign(size_t index, MuType* obj){
		list.assign(index, obj);
	}
};

class TBlock : MuType{
public:
	static const char tid = TBLOCK;
	map<string, MuType*> locals, &upvalues;
	char* code;
	TBlock(map<string, MuType*> &upvalues,
		map<string, MuType*> locals,
		char* code) :
			upvalues(upvalues), locals(locals), code(code) {}
};

class TFunc : MuType{
public:
	static const char tid = TFUN;
	TBlock code;
	list<string> args;
	TFunc(TBlock code, list<string> args) :
		code(code), args(args) {}
};

#endif /* TYPE_H_ */
