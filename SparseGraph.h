//===============================================================
// SparseGraph.h
// Header file of SparseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>

#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

template <typename T>
class SparseGraph : public Graph { //example of how inheritance works
public:
				// no need for construcor and destructor i think?
			SparseGraph	(int V, int E);
			~SparseGraph	(void);
	SparseGraph<T>	operator=	(const Graph<T> &graph1);
	bool		isEdge		(int v1, int v2) const override;
	T		getWeight	(int v1, int v2) const override;
	void		insertEdge	(int v1, int v2, T w) const override;

private:
	struct AdjecencyListNode // this should be a linked list
	{
		int vertex;
		T weight;
		AdjecencyListNode* next;
		
		AdjecencyListNode (int v, T w)
		{
			vertex = v;
			weight = w;
			next = NULL;
		}
	};
	
	AdjecencyListNode** list
};

#endif



