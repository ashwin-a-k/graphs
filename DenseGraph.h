//===============================================================
// DenseGraph.h
// Implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

#include <vector>
#include "Graph.h"

class DenseGraph : public Graph {
public:
    DenseGraph(); 
    DenseGraph(int V, int E); 
    ~DenseGraph(); 
    DenseGraph(const DenseGraph& other); 
    DenseGraph& operator=(const DenseGraph& other);

    bool isEdge(int v1, int v2) const;
    int getWeight(int v1, int v2) const;
    void insertEdge(int v1, int v2, int w);

private:
    std::vector<std::vector<int>> matrix; 
};
