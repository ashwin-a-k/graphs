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
 	SparseGraph&	operator =	(const SparseGraph& graph);
    			~SparseGraph	();

    //SparseGraph& 	operator=	(const SparseGraph& graph);
    
   
    
    
    bool 		isEdge		(int v1, int v2) override;
    int 			getWeight	(int v1, int v2) override;
    void 		insertEdge	(int v1, int v2, int w) override;
/*
    friend std::istream& operator>>(std::istream& input, SparseGraph& graph) {
        int V, E, v1, v2, w;
        input >> V >> E;
        SparseGraph graph1(V, E);
        for (int i = 0; i < E; ++i) {
            input >> v1 >> v2 >> w;
            graph1.insertEdge(v1, v2, w);
        }
        graph = &graph1;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& os, const SparseGraph& graph) {
        for (int i = 0; i < graph.list.size(); ++i) {
            os << i << ": ";
            for (const auto& node : graph.list[i]) {
                os << "(" << node.vertex << ", " << node.weight << ") ";
            }
            os << std::endl;
        }
        return os;
    }

*/
private:
    struct AdjacencyListNode {
        int vertex;
        int weight;

        AdjacencyListNode(int v, int w) : vertex(v), weight(w) {}
    };

    std::vector<std::vector<AdjacencyListNode>> list; // Adjacency list
};

#endif // SPARSEGRAPH_H
