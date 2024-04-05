//===============================================================
// Graph.cpp
// implementation of Graph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include "Graph.h"


// constuctor
template <class T>
Graph<T>::Graph ( void )
{
	numVerticies = 0;
	numEdges = 0;
}

// constructor with parameters
template <class T>
Graph<T>::Graph (int V, int E)
{
	numVerticies = V;
	numEdges = E;
}

// Copy Constructor
template <class T>
Graph<T>::Graph (const Graph& graph1)
{
	numVerticies = graph1.numVerticies;
	numEdges = graph1.numEdges;
}

// The rest of this class it virtual, polymorphism takes place

