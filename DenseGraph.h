//===============================================================
// DenseGraph.h
// Implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

#include <vector>
#include <iostream>
#include "Graph.h"

class DenseGraph : public Graph {
public:
    DenseGraph(); 
    DenseGraph(int V, int E); 
    ~DenseGraph(); 
    DenseGraph(const DenseGraph& other); 
    Graph& operator=(Graph* mygraph);

    bool isEdge(int v1, int v2);
    int getWeight(int v1, int v2);
    void insertEdge(int v1, int v2, int w);
    
    friend std::istream& operator>>(std::istream& input, DenseGraph& graph) {
        int V, E, v1, v2, w;
        input >> V >> E;
        DenseGraph graph1(V, E);
        for (int i = 0; i < E; ++i) {
            input >> v1 >> v2 >> w;
            graph1.insertEdge(v1, v2, w);
        }
        graph = &graph1;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& os, const DenseGraph& graph) {
        for (int i = 0; i < graph.numVerticies; ++i) {
            for (int j = 0; j < graph.numVerticies; ++j) {
                os << graph.matrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }


private:
    std::vector<std::vector<int>> matrix; 
};
