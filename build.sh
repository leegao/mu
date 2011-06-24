lex -o tokens.cpp mu.l
bison -d -o parser.cpp mu.y
g++ -omu -I"re2/re2/" -L"re/re2/obj/so/libre2.so" mu.cpp parser.cpp tokens.cpp node.cpp