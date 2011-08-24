DIR_GTEST         = /usr/local/Cellar/gtest/1.5.0
DIR_GTEST_INCLUDE = $(DIR_GTEST)/include
DIR_GTEST_LIB     = $(DIR_GTEST)/lib

DIR_BIN   = bin
DIR_BUILD = build
DIR_LIB   = lib
DIR_SRC   = src

# XXX Can we really use clang and g++ together?
CC         = clang
CPP        = g++
LINK_LIBS  = $(DIR_GTEST_LIB)/libgtest.dylib
GTEST_WARN = -Wno-variadic-macros -Wno-long-long
WARN       = -Wall -Wextra -ansi -pedantic $(GTEST_WARN)
TWEAK      = -O4 -fPIC

all: trim list

trim:
	@- trim $(DIR_SRC)/**/* $(DIR_LIB)/**/*
	clear

clean: trim
	rm -rf $(DIR_BIN)/* $(DIR_BUILD)/*

### List

list:
	@- mkdir -p $(DIR_BIN) $(DIR_BUILD)/list
	make $(DIR_BIN)/list
	$(DIR_BIN)/list

$(DIR_BIN)/list: $(DIR_BUILD)/list/list.o $(DIR_BUILD)/list/list_test.o
	@- echo '--- Linking $@ ...'
	$(CPP) -o $@ $^ $(LINK_LIBS)

$(DIR_BUILD)/list/%.o: $(DIR_SRC)/list/%.c $(DIR_LIB)/list/*.h Makefile
	@- echo '--- Compiling C $< ...'
	$(CC) -o $@ -c $< $(WARN) $(TWEAK) -I$(DIR_LIB) -I$(DIR_GTEST_INCLUDE)

$(DIR_BUILD)/list/%.o: $(DIR_SRC)/list/%.cpp $(DIR_LIB)/list/*.h Makefile
	@- echo '--- Compiling C++ $< ...'
	$(CPP) -o $@ -c $< $(WARN) $(TWEAK) -I$(DIR_LIB) -I$(DIR_GTEST_INCLUDE)
