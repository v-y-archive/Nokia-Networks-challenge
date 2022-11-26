CXX = clang++
CFLAGS = -c -std=c++2a -Os -Werror -Wall -Wextra -Wsign-conversion -Wvla -fstack-protector -Iinclude
LFLAGS =
SRC = $(wildcard src/*.cpp)
OBJ = $(patsubst %.cpp,%.o,$(SRC))
EXEC = main
TESTS = $(wildcard test/*.cpp)
TESTOBJ = $(patsubst %.cpp,%.o,$(TESTS))

test: $(TESTOBJ)
	$(CXX) $(LFLAGS) $^ -o test/test
	test/test

test/%.test.o: src/%.cpp test/%.test.cpp
	$(CXX) $(CFLAGS) test/$*.test.cpp -o test/$*.test.o
test/Test.o: test/Test.cpp
	$(CXX) $(CFLAGS) test/Test.cpp -o test/Test.o

.PHONY: clean tidy format

clean:
	rm -rf src/*.o test/*.o test/test $(EXEC)

tidy:
	clang-tidy -fix -fix-errors -header-filter=.* \
	--checks=misc-macro-parentheses src/* -- -I.

format:
	clang-format -i -style=file src/*

tf: tidy format