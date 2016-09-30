parser: lex.yy.c binary.tab.o main.cpp
	g++ --std=c++11 -oparser binary.tab.o lex.yy.c main.cpp -o comp
binary.tab.o: binary.tab.cc
	g++ --std=c++11 -c binary.tab.cc
binary.tab.cc: binary.yy
	bison binary.yy
lex.yy.c: binary.ll binary.tab.cc
	flex binary.ll
clean:
	rm -f binary.tab.* lex.yy.c* int stack.hh
