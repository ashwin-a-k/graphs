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
Graph::Graph ( void )
{
	numVerticies = 10;
	numEdges = 0;
}

// constructor with parameters
Graph::Graph (int V, int E)
{
	numVerticies = V;
	numEdges = E;
}

// Copy Constructor
Graph::Graph (Graph * graph1)
{
	numVerticies = graph1->numVerticies;
	numEdges = graph1->numEdges;
}

Graph::~Graph ( void )
{
	// nothing goes here, nothing to deallocate
}


bool	Graph::isEdge		(int v1, int v2)
{
}
int	Graph::getWeight	(int v1, int v2)
{
}
void	Graph::insertEdge	(int v1, int v2, int w)
{
}

// The rest of this class it virtual, polymorphism takes place

