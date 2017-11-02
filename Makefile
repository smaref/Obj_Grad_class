OBJ=obj
BIN=bin
SRC=src
INC=include
TEST=test
LIB=lib
	
OBJS=$(OBJ)/vector.o $(OBJ)/matrix.o $(OBJ)/sparse_matrix.o $(OBJ)/blocked_matrix.o $(OBJ)/sparse_blocked.o

# C Compiler Flags
CFLAGS=

# CC Compiler
CXX=icpc

# CC Compiler Flags
CCFLAGS= 
CXXFLAGS= -std=c++11 -fPIC# -DPRINT

all: mkd clean test_rw test_fg

mkd:
	mkdir -p $(OBJ)
	mkdir -p $(BIN)
	mkdir -p $(LIB)

test_rw: $(SRC)/testRW.cpp $(SRC)/vector.cpp $(SRC)/matrix.cpp $(SRC)/sparse_matrix.cpp $(SRC)/blocked_matrix.cpp $(SRC)/sparse_blocked.cpp  mkd
	$(CXX) $(CXXFLAGS) -c $(SRC)/vector.cpp -o -I$(INC) $(OBJ)/vector.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/matrix.cpp -o -I$(INC) $(OBJ)/matrix.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/sparse_matrix.cpp -o -I$(INC) $(OBJ)/sparse_matrix.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/blocked_matrix.cpp -o -I$(INC) $(OBJ)/blocked_matrix.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/sparse_blocked.cpp -o -I$(INC) $(OBJ)/sparse_blocked.o
	$(CXX) -shared -o lib/libsahar.so $(OBJS)
	$(CXX) $(CXXFLAGS) -c $< -I$(INC) -o $(OBJ)/$@.o
	$(CXX) $(CXXFLAGS) -Llib -lsahar -o $(BIN)/$@   $(OBJ)/$@.o

run_test_rw: test_rw
	$(BIN)/test_rw

test_fg: $(SRC)/testfg.cpp mkd
	$(CXX) $(CXXFLAGS) $< -I$(INC) -o $(BIN)/$@ 



clean:
	rm -if $(OBJ)/*
	rm -if $(BIN)/*
