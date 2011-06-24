lex -o tokens.cpp mu.l
bison -d -o parser.cpp mu.y
g++ -omu mu.cpp parser.cpp tokens.cpp node.cpp