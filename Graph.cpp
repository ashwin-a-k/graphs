//===============================================================
// Graph.cpp
// implementation of Graph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include <vector>
#include <queue>
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


//BFS starts here
void 	Graph::BFS 			( int source )
{
	vector<int> d(numVertices, INT_MAX);
	queue<int> q;
	
	d[source] = 0;
	q.push(source);
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		for (int i = 0; i < numVertices; i++)
		{
			if (isEdge(current, i) and d[i] = INT_MAX) 
			{
				d[i] = d[curr] + 1;
				q.
			}
		}
	}
}

void	Graph::printBFSTable		( int source )
{

}


void 	Graph::printBFSPath		( int s, int d)
{

}

void	Graph::printMostDistant	( int s )
{

}

bool	Graph::isConnected		( void )
{

}

//DFS Starts here
void	Graph::DFS			( void )
{
	int clock = 0;
	for (Vertex &u : verticies)
	{
		u.color = WHITE;
		u.pi = NULL;
	}
	time = 0;
	for (Vertex &u : verticies)
	{
		if (u.color = WHITE)
		{
			DFS_Visit(&u);
		}
	}
}

void 	Graph::DFS_Visit		( int v, int &clock )
{
	Vertex* vVert = &vertices[v]
	clock+=1
	uVert->d = clock;
	uVert->color = GRAY;
	
	for ( int u : adjList[v])
	{
		Vertex* uVert = &vertices[u];
		if (uVert->color == WHITE)
		{
			uVert->pi = vVert;
			DFS_Visit(u, clock);
		}
	}
	clock+=1;
	vVert->clock;
	vVert->color = BLACK;
}

void 	Graph::printDFSTable		( void )
{
	if (vertices.size() > 10)
	{
		cout << "Should not print out because it is greater than 10";
		return;
	}
	std::cout << "Vertex\tDiscovered\tFinished\tPredecessor" << std::endl;
	for (size_t i = 0; i < vertices.size(); i++) //author: size_t is used for vectors, no int
	{
		std::cout << i << "\t\t" << vertices[i].d << "\t\t" << vertices[i].f << "\t\t";
		if(vertices[i].pi != NULL)
		{
			int prev = vertices[i].pi - &vertices[0];
			std::cout << prev;
		}
		else
			std::cout << "NULL"
		std:cout << std::endl;
	}
}

/*void	Graph::printTopologicalSort	( void ) // did not learn in class, told to skip
{

}*/

void	Graph::printDFSParethesization ( void )
{

}

void	Graph::classifyDFSEdges	( void )
{

}

/*void	Graph::indexSort		( int a[] ) // did not learn in class, told to skip (used in topolgical sort
{

}*/









