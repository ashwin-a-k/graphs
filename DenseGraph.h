//===============================================================
// DenseGraph.h
// implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include <vector>

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H


class DenseGraph : public Graph { //example of how inheritance works
public:
				
			DenseGraph	( void );
			DenseGraph	(int V, int E);
 			~DenseGraph	(void) override;
			DenseGraph	(const DenseGraph& graph1) override;
	DenseGraph<T>	operator=	(const DenseGraph<T> &graph1) override;
	bool		isEdge		(int v1, int v2) override;
	int		getWeight	(int v1, int v2) override;
	void		insertEdge	(int v1, int v2, int w) override;

protected:
	
	int** twodimensionlist; 
};

#endif

