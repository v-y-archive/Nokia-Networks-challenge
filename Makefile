CXX=clang++-10
CFLAGS=-c -std=c++20 -Wall -Wextra -Wsign-conversion -Wvla -Werror \
	-fstack-protector #-fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all
LFLAGS=

test: Task1.test.o Task2.test.o Task3.test.o Task4.test.o Task5.test.o Test.o
	$(CXX) $(LFLAGS) $^ -o test

%.test.o: src/%.cpp src/%.test.cpp
	$(CXX) $(CFLAGS) src/$*.test.cpp
Test.o: src/Test.cpp
	$(CXX) -c -std=c++20 src/Test.cpp

.PHONY: clean tidy format wtf

clean:
	rm -rf *.o test

tidy:
	clang-tidy -fix -fix-errors -header-filter=.* \
	--checks=misc-macro-parentheses src/* -- -I.

format:
	clang-format -i -style=file src/*

tf: tidy format