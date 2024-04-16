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
#include <climits>
#include "Graph.h"


// constuctor
Graph::Graph ( void )
{
	numVertices = 10;
	numEdges = 0;
}

// constructor with parameters
Graph::Graph (int V, int E)
{
	numVertices = V;
	numEdges = E;
}

// Copy Constructor
	Graph::Graph 			(const Graph& mygraph)
{
	numVertices = mygraph.numVertices;
	numEdges = mygraph.numEdges;
}
// Assignment Operator

Graph&	Graph::operator=		(const Graph& mygraph)
{
	numVertices = mygraph.numVertices;
	numEdges = mygraph.numEdges;
	
	return *this;

}


	Graph::~Graph 			( void )
{
	// nothing goes here, nothing to deallocate
}


bool 	Graph::isEdge			(int v1, int v2) {

    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
    
        for (Vertex* v : vertices[v1].adjList) {
            if (v->id == v2) {
                return true;
            }
        }
    }
    return false;
}

int 	Graph::getWeight		(int v1, int v2) 
{

    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        return isEdge(v1, v2) ? 1 : 0;
    }
    return 0;
}

void 	Graph::insertEdge		(int v1, int v2, int w) 
{

    if (v1 >= 0 && v1 < numVertices && v2 >= 0 && v2 < numVertices) {
        if (!isEdge(v1, v2)) {
            vertices[v1].adjList.push_back(&vertices[v2]);
            numEdges++;
        }
    }
}




//BFS starts here
void 	Graph::BFS			(int source) 
{

    for (auto& vertex : vertices) {
        vertex.color = WHITE;
        vertex.d = std::numeric_limits<int>::max();
        vertex.pi = nullptr;
    }
    

    vertices[source].color = GRAY;
    vertices[source].d = 0;
    vertices[source].pi = nullptr;


    std::queue<int> Q;
    Q.push(source);


    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (Vertex* v : vertices[u].adjList) {
            if (v->color == WHITE) {
                v->color = GRAY;
                v->d = vertices[u].d + 1;
                v->pi = &vertices[u];
                Q.push(v->id);
            }
           
        }
        
        vertices[u].color = BLACK;
    }
    
}


void 	Graph::printBFSTable		(int source) 
{

    std::cout << "Vertex | Distance | Color | Pi" << std::endl;
    
    for (const Vertex& vertex : vertices) {
        std::cout << vertex.id << " | " << vertex.d << " | " << vertex.color << " | ";
        
        if (vertex.pi != nullptr)
            std::cout << vertex.pi->id;
            
        else
            std::cout << "NULL";
        std::cout << std::endl;
    }
}


void 	Graph::printBFSPath		(int s, int d) 
{

    BFS(s);

    if (vertices[d].color == WHITE) {
        std::cout << "No path from v" << s << " to v" << d << " exists" << std::endl;
        return;
    }

    std::vector<int> path;

    for (Vertex* v = &vertices[d]; v != nullptr; v = v->pi) {
        path.push_back(v->id);
    }

    std::reverse(path.begin(), path.end());

    std::cout << "Path from v" << s << " to v" << d << ": ";
    
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << "v" << path[i];
        if (i < path.size() - 1)
            std::cout << " -> ";
    }
    
    std::cout << std::endl;
}

void 	Graph::printMostDistant	(int s) 
{

    BFS(s);

    int max_d = 0;
    std::vector<int> dvert;

    for (const Vertex& v : vertices) {
        if (v.d != std::numeric_limits<int>::max() && v.d > max_d) {
            max_d = v.d;
            dvert.clear();
            dvert.push_back(v.id);
        } else if (v.d == max_d) {
            dvert.push_back(v.id);
        }
    }

    std::cout << "Most distant vertices from source v" << s << " are: ";
    
    for (int id : dvert) {
        std::cout << "v" << id << " (dist=" << max_d << ") ";
    }
    
    std::cout << std::endl;
}

bool 	Graph::isConnected		(void) 
{

    BFS(0);

    bool connected = true;
    for (const Vertex& vertex : vertices) {
        if (vertex.color == WHITE) {
            connected = false;
            break;
        }
    }

    std::cout << "Graph is " << (connected ? "connected" : "not connected") << std::endl;
    return connected;
}

//DFS Starts here
void	Graph::DFS			( void )
{
	int clock = 0;
	for (int i = 0; i < numVertices; i++)
	{
		vertices[i].color = WHITE;
		vertices[i].pi = NULL;
		vertices[i].d = -1;
		vertices[i].f = -1;
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
	clock++;
	vertices[u].d = clock;
	vertices[u].color = GRAY;
	
	for ( Vertex* v : vertices[u].adjList )
	{
		if (v->color == WHITE) 
		{
            		v->pi = &vertices[u];
            		DFS_Visit(v->id, clock);
		}
	}
	clock++;
	vertices[u].f = clock;
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
			std::cout << "NULL";
		std:cout << "(" << vertices[i].d << "," << vertices[i].f;
		std::cout << ")" << std::endl;
	}
}

/*void	Graph::printTopologicalSort	( void ) // did not learn in class, told to skip
{
	
}*/

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

void 	Graph::DFSParethesizationHelper(int v, std::vector<bool> visited, std::string& parenth)
{
	visited[v] = true;
	parenth += "(v" + std::to_string(v) + " ";
	
	for (Vertex* u : vertices[v].adjList) 
	{
		if (!visited[u->id]) 
		{
			parenth += " ";
			DFSParethesizationHelper(u->id, visited, parenth);
        	}
    	}
	parenth += "v" + std::to_string(v) + ") ";
}

void Graph::classifyDFSEdges(void) {

	for (int u = 0; u < numVertices; u++) 
	{
		for (Vertex* v : vertices[u].adjList) 
		{        
			if (vertices[u].d < v->d && v->d < v->f && v->f < vertices[u].f) 
			{
				std::cout << "Edge (" << u << "," << v->id; 
				std::cout << ") is a tree/forward edge" << std::endl;
            		}
            		if (v->d < vertices[u].d && vertices[u].d < vertices[u].f && 
            								vertices[u].f < v->f) 
            		{
            			std::cout << "Edge (" << u << "," << v->id << ") is a back edge";
            			std::cout << std::endl;
            		}
            		if (v->d < v->f && v->f < vertices[u].d && vertices[u].d < vertices[u].f) 
            		{
            			std::cout << "Edge (" << u << "," << v->id;
            			std::cout << ") is a cross edge" << std::endl;
            }
        }
    }
}










