GCC=gcc
CPPFLAGS=-std=c99
LDFLAGS=
LIBS=-lgtest -lpthread

SRC=src
OBJ=obj
BIN=bin
TEST=test

OBJECTS := $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(wildcard $(SRC)/*.c))
HEADERS := $(wildcard $(SRC)/*.h)

UT_OBJECTS := $(filter-out $(OBJ)/main.o, $(OBJECTS))
UT_HEADERS := $(wildcard $(TEST)/*.h)

all: dirs $(BIN)/main

# link main
$(BIN)/main: $(OBJECTS)
	$(GCC) -Wall $(CPPFLAGS) -o $@ $^

# link ut
$(BIN)/ut_main: $(OBJ)/ut_main.o $(UT_OBJECTS)
	$(GCC) -Wall $(CPPFLAGS) -o $@ $^ $(LIBS)

# compile source
$(OBJ)/%.o: $(SRC)/%.c $(HEADERS)
	$(GCC) -Wall $(CPPFLAGS) -c -o $@ $<

# compile ut_main
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(HEADERS) $(UT_HEADERS)
	$(GCC) -Wall $(CPPFLAGS) -c -o $@ $<

test: all
	$(BIN)/ut_main

clean:
	rm -rf bin/* obj/*

dirs:
	mkdir -p bin obj
