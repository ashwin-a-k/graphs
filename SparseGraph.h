// SparseGraph.h
#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <vector>
#include "Graph.h"

class SparseGraph : public Graph {
public:

    			SparseGraph	();
    			SparseGraph	(int V, int E);
    			SparseGraph	(const SparseGraph& graph);
    			~SparseGraph	();

    //SparseGraph& 	operator=	(const SparseGraph& graph);
    
    SparseGraph&	operator=	( Graph * mygraph) override;
    
    
    bool 		isEdge		(int v1, int v2) override;
    int 		getWeight	(int v1, int v2) override;
    void 		insertEdge	(int v1, int v2, int w) override;

private:
    struct AdjacencyListNode {
        int vertex;
        int weight;

        AdjacencyListNode(int v, int w) : vertex(v), weight(w) {}
    };

    std::vector<std::vector<AdjacencyListNode>> list; // Adjacency list
};

#endif // SPARSEGRAPH_H
