//===============================================================
// DenseGraph.cpp
// Implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

#include "DenseGraph.h"
#include <vector>
#include <stdexcept>

DenseGraph::DenseGraph() : Graph(10, 0) {
    matrix.resize(10, std::vector<int>(10, -1)); // Default size with -1 indicating no edge
}

DenseGraph::DenseGraph(int V, int E) : Graph(V, E) {
    matrix.resize(V, std::vector<int>(V, -1));
}

DenseGraph::~DenseGraph() {
    // Destructor - vector handles memory!
}

DenseGraph::DenseGraph(const DenseGraph& graph1) : Graph(graph1) {
    matrix = graph1.matrix;
}

DenseGraph& DenseGraph::operator=(const DenseGraph& graph1) {
    if (this != &graph1) {
        Graph::operator=(graph1);
        matrix = graph1.matrix;
    }
    return *this;
}

bool DenseGraph::isEdge(int v1, int v2) const {
    if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices)
        throw std::out_of_range("Vertex index out of range");
    return matrix[v1][v2] != -1;
}

int DenseGraph::getWeight(int v1, int v2) const {
    if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices)
        throw std::out_of_range("Vertex index out of range");
    if (matrix[v1][v2] == -1)
        throw std::logic_error("Edge doesn't exist");
    return matrix[v1][v2];
}

void DenseGraph::insertEdge(int v1, int v2, int w) {
    if (v1 < 0 || v1 >= numVertices || v2 < 0 || v2 >= numVertices)
        throw std::out_of_range("Vertex index out of range");
    matrix[v1][v2] = w;
#ifndef DIRECTED_GRAPH
    matrix[v2][v1] = w;
#endif
}
