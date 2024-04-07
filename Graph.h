//===============================================================
// Graph.h
// Header file of Graph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
			Graph		(void);
			Graph		(int V, int E);
			Graph		(const Graph& graph1);
virtual 		~Graph		(void) = 0;
virtual	Graph	operator=	(const Graph &graph1) = 0;
virtual	bool	isEdge		(int v1, int v2) = 0;
virtual	int	getWeight	(int v1, int v2) = 0;
virtual	void	insertEdge	(int v1, int v2, int w) = 0;

protected:
	int numVerticies;
	int numEdges;
};

#endif
	

