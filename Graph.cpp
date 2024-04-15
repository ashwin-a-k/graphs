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
#include <string>
#include <stack>
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
	for (int i = 0; i < numVertices; i++)
	{
		vertices[i].color = WHITE;
		vertices[i].pi = NULL;
		vertices[i].dTime = -1;
		vertices[i].fTime = -1;
	}
	for (int u = 0; u < numVertices; u++)
	{
		if (vertices[u].color = WHITE)
		{
			DFS_Visit(u, clock);
		}
	}
}

void 	Graph::DFS_Visit		( int u, int &clock ) //assigment says use v, i will use u like the book
{
	Vertex* vVert = &vertices[v]
	clock++;
	vertices[u].dTime = clock;
	vertices[u].color = GRAY;
	
	for ( int v : adjList[u])
	{
		if (vertices[v].color == WHITE)
		{
			vertices[v].pi = &vertices[u];
			DFS_Visit(v, clock);
		}
	}
	clock+=1;
	vertices[u].fTime = clock;
	vertices[u].color = BLACK;
}

void 	Graph::printDFSTable		( void )
{
	if (vertices.size() > 10)
	{
		cout << "Should not print out because it is greater than 10";
		return;
	}
	std::cout << "DFS Table for Source Node" << std::endl;
	for (int i = 0; i < numVertices; i++)
	{
		std::cout << "[" << i << "]";
		std::cout << "dist: -1"; //no distance in DFS!
		if(vertices[i].pi != NULL)
		{
			int prev = vertices[i].pi - &vertices[0];
			std::cout << "pred: " << prev << " ";
		}
		else
			std::cout << "NULL"
		std:cout << "(" << vertices[i].dTime << "," << vertices[i].fTime;
		std::cout << ")" << std::endl;
	}
}

void	Graph::printTopologicalSort	( void ) // did not learn in class, told to skip
{
	std::priority_queue<int> pq;
	for (int u = 0; u < numVertices; u++)
	{
		pq.push(vertices[u].fTime);
	}
	
	for (int i = 0; i < pq.size(); i++)
	{
		if ()
		std::cout << i 
	}
	
}

void	Graph::printDFSParethesization ( void )
{
	std::string p;
	std::vector<bool> visit (numVertices, false);
	for (int i = 0; i < numVertices; i++)
	{
		if (!visit[i])
		{
			DFSParethesizationHelper(i, visit, p);
		}
	}
}

void 	Graph::DFSParethesizationHelper(int v, std::vector<bool> visit, std::string& parenth)
{
	visit[v] = true;
	parenth += "(v" + std::to_string(v) + " ";
	for (int i : adjList[v])
	{
		if (!visit[i])
		{
			DFSParethesizationHelper(i, visit, parenth)
		}
	}
	parenth += "v" + std::to_string(v) + ") ";
}

void	Graph::classifyDFSEdges	( void )
{
	for (int u = 0; u < numVertices; u++)
	{
		for (int v : adjList[u])
		{
			if ( vertices[u].dTime < vertices[v].dTime && vertices[v].dTime
			< vertices[v].fTime && vertices[v].fTime < vertices[u].fTime )
			{
				std::cout << "Edge (" << vertices[u] << "," << vertices[v];
				std::cout << ") is a tree/forward edge" << endl;
			}
			if ( vertices[v].dTime < vertices[u].dTime && vertices[u].dTime
			< vertices[u].fTime && vertices[u].fTime < vertices[v].fTime )
			{
				std::cout << "Edge (" << vertices[u] << "," << vertices[v];
				std::cout << ") is a back edge" << endl;
			}
			if ( vertices[v].dTime < vertices[v].fTime && vertices[v].fTime
			< vertices[u].dTime && vertices[u].dTime < vertices[u].fTime )
			{
				std::cout << "Edge (" << vertices[u] << "," << vertices[v];
				std::cout << ") is a cross edge" << endl;
			}
			
		}
	}
}

/*void	Graph::indexSort		( int a[] ) // did not learn in class, told to skip (used in topolgical sort
{

}*/









