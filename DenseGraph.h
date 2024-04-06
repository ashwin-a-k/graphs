//===============================================================
// DenseGraph.cpp
// implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>

#ifndef DENSEGRAPH_H
#define DENSEGRAPH_H


template <typename T>
class SparseGraph : public Graph { //example of how inheritance works
public:
				
			DenseGraph	(int V, int E);
 			~DenseGraph	(void);
			DenseGraph	(const DenseGraph& graph1)
	DenseGraph<T>	operator=	(const DenseGraph<T> &graph1);
	bool		isEdge		(int v1, int v2) const override;
	T		getWeight	(int v1, int v2) const override;
	void		insertEdge	(int v1, int v2, T w) const override;

private:
	
	T** twodimensionlist; // may need more? Have to look more into what exactly dense graph is.
};

#endif

