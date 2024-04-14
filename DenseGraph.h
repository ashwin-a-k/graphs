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

    std::istream& operator>>(std::istream& input, DenseGraph& graph) {
        int V, E, v1, v2, w;
        input >> V >> E;
        DenseGraph temp(V, E);
        for (int i = 0; i < E; ++i) {
            input >> v1 >> v2 >> w;
            temp.insertEdge(v1, v2, w);
        }
        graph = &temp;
        return input;
    }

    std::ostream& operator<<(std::ostream& os, const DenseGraph& graph) {
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
