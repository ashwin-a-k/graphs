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
				// no need for constructor, and copy constructor
				DenseGraph	(int V);
virtual 			~DenseGraph	(void);
		DenseGraph<T>	operator=	(const DenseGraph<T> &graph1);
virtual	bool		isEdge		(int v1, int v2) const override;
virtual	T		getWeight	(int v1, int v2) const override;
virtual	void		insertEdge	(int v1, int v2, T w) const override;

private:
	
	T** twodimensionlist; // may need more? Have to look more into what exactly dense graph is.
};

#endif

