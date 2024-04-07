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
	 		~Graph		(void);
virtual	Graph	operator=	(const Graph &graph1) const = 0;
virtual	bool	isEdge		(int v1, int v2) const = 0;
virtual	int	getWeight	(int v1, int v2) const = 0;
virtual	void	insertEdge	(int v1, int v2, int w) const = 0;

private:
	int numVerticies;
	int numEdges;
};

#endif
	

