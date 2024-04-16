all: main maind

#maind: main_a_level.cpp Graph.cpp Graph.h DenseGraph.cpp DenseGraph.h SparseGraph.cpp SparseGraph.h
#	g++ -std=c++2a -o maind -DDIRECTED_GRAPH main_a_level.cpp Graph.cpp DenseGraph.cpp #SparseGraph.cpp

#main: main_a_level.cpp Graph.cpp Graph.h DenseGraph.cpp DenseGraph.h SparseGraph.cpp SparseGraph.h
#	g++ -std=c++2a -o main main_a_level.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

#main: main_a_level.o Graph.o DenseGraph.o SparseGraph.o
#	g++ -std=c++2a -o main main_a_level.o Graph.o DenseGraph.o SparseGraph.o

#maind: main_a_level.cpp Graph.h DenseGraph.h SparseGraph.h
#	g++ -std=c++2a -c main_a_level.cpp

maind: main_a_level.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o maind -DDIRECTED_GRAPH main_a_level.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

main: main_a_level.cpp Graph.cpp Graph.h DenseGraph.h DenseGraph.cpp SparseGraph.h SparseGraph.cpp
	g++ -std=c++2a -o main main_a_level.cpp Graph.cpp DenseGraph.cpp SparseGraph.cpp

