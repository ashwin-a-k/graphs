//===============================================================
// DenseGraph.cpp
// implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include <vector>
#include "DenseGraph.h"

// #ifndef DIRECTED_GRAPH Directed Graphs

// #ifndef UNDIRECTED_GRAPH  Undirected graph <- in specific implementations in insertEdge and other places

DenseGraph::DenseGraph ( void ) : Graph (void)
{
	// empty because same as default class
}


DenseGraph::DenseGraph ( int V, int E ): Graph (V, E)
{
	twodimensionlist = new int*[V];
	for (int i = 0; i < V; i++)
	{
		twodimensionlist = new int[V]
		for (int j = 0; j < V; j++)
			twodimensionlist[i][j] = -1;
	}
}


DenseGraph::~DenseGraph ( void )
{
	for (int i = 0; i < V; i++)
	{
		delete[] twodimensionlist[i];
	}
	delete[] twodimensionlist;
}

DenseGraph::DenseGraph(const DenseGraph &graph1) : Graph(graph1.numVerticies, other.numEdges)
{
	twodimensionlist = new int*[this->numVerticies];
	for (int i = 0; i < this->numVerticies; i++)
	{
		twodimensionlist[i] = new int[this->numVerticies];
		for (int j = 0; j < this->numVerticies; j++)
		{
			twodimensionlist[i][j] = graph1.twodimensionlist[i][j];
		}
	}
}

// assignment operator
DenseGraph	DenseGraph::operator=(const DenseGraph &graph1)
{
	if (*this != &graph1)
	{
		for (int i = 0; i < V; i++)
		{
			delete[] twodimensionlist[i];
		}
		delete[] twodimensionlist;
	}
	numVerticies = graph1.V;
	numEdges = graph1.E;
	
	twodimensionlist = new int*[this->numVerticies];
	for (int i = 0; i < this->numVerticies; i++)
	{
		twodimensionlist[i] = new int[this->numVerticies];
		for (int j = 0; j < this->numVerticies; j++)
		{
			twodimensionlist[i][j] = graph1.twodimensionlist[i][j];
		}
	}
	
	
}

//isEdge
bool DenseGraph::isEdge(int v1, int v2)
{
	// don't have to specify undirected or directed because assumed 
	if (v1 < 0 or v1 >= V or v2 < 0 or v2 >= V)
		throw out_of_range("Index out of range");  
	if (twodimensionlist[v1][v2] == -1)
		return false;
	return true;
}

//getWeight
int DenseGraph::getWeight(int v1, int v2)
{
	if (v1 < 0 or v1 >= numVerticies or v2 < 0 or v2 >= numVerticies)
		throw out_of_range("Index out of range");  
	return twodimensionlist[v1][v2];
}

//insertEdge
void DenseGraph::insertEdge (int v1, int v2, int w)
{
	if (v1 < 0 or v1 >= numVerticies or v2 < 0 or v2 >= numVerticies)
		throw out_of_range("Index out of range");
	twodimensionlist[v1][v2] = w;
	#ifndef DIRECTED_GRAPH
	twodimensionlist[v2][v1] = w;
	#endif
	
}



