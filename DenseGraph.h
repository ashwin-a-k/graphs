//===============================================================
// DenseGraph.h
// implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include <vector>
#include "Graph.h"

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H


class DenseGraph : public Graph { //example of how inheritance works
public:
				
			DenseGraph	( void );
			DenseGraph	(int V, int E);
 			~DenseGraph	(void);
			DenseGraph	(Graph * graph1);
	DenseGraph&	operator=	(Graph * graph1);
	bool		isEdge		(int v1, int v2);
	int		getWeight	(int v1, int v2);
	void		insertEdge	(int v1, int v2, int w);
   friend istream& operator >> ( istream& input, Graph * graph)
   {
   	return input;
   }
   friend ostream& operator << ( ostream& os, Graph * graph)
   {
   	return os;
   }
private:
	
	int** twodimensionlist; 
};

#endif

