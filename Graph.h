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

template <typename T>
class Graph {
public:
				Graph		(void);
				Graph		(int V, int E);
				Graph		(const Graph& graph1);
virtual 			~Graph		(void);
		Graph<T>	operator=	(const Graph<T> &graph1);
virtual	bool		isEdge		(int v1, int v2) const = 0;
virtual	T		getWeight	(int v1, int v2) const = 0;
virtual	void		insertEdge	(int v1, int v2, T w) const = 0;

private:
	int numVerticies;
	int numEdges;
};

#endif
	

