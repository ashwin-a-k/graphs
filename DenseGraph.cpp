//===============================================================
// DenseGraph.cpp
// Implementation of DenseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

#include <iostream>
#include "DenseGraph.h"
#include <vector>
#include <stdexcept>

DenseGraph::DenseGraph() : Graph(10, 0) {
    matrix.resize(10, vector<int>(10, -1)); // Default size with -1 indicating no edge
}

DenseGraph::DenseGraph(int V, int E) : Graph(V, E) {
    matrix.resize(V, vector<int>(V, -1));
}

DenseGraph::DenseGraph(const DenseGraph& graph1) : Graph(graph1) {
    matrix = graph1.matrix;
}


DenseGraph::~DenseGraph() {
    // Destructor - vector handles memory!
}


Graph& DenseGraph::operator=(const DenseGraph& mygraph) {
    if (this != mygraph) {
        DenseGraph* graph1 = dynamic_cast<DenseGraph*>(mygraph);
        if (graph1) 
        {
            for (int i = 0; i < numVerticies; i++) 
            {
                for (int j = 0; j < numVerticies; j++)
                    matrix[i][j] = graph1->matrix[i][j];
            }
            numVerticies = graph1->numVerticies;
            numEdges = graph1->numEdges;
        }
    }
    return *this;
}

bool DenseGraph::isEdge(int v1, int v2) {
    if (v1 < 0 || v1 >= numVerticies || v2 < 0 || v2 >= numVerticies)
        throw out_of_range("Vertex index out of range");
    return matrix[v1][v2] != -1;
}

int DenseGraph::getWeight(int v1, int v2) {
    if (v1 < 0 || v1 >= numVerticies || v2 < 0 || v2 >= numVerticies)
        throw out_of_range("Vertex index out of range");
    if (matrix[v1][v2] == -1)
        throw logic_error("Edge doesn't exist");
    return matrix[v1][v2];
}

void DenseGraph::insertEdge(int v1, int v2, int w) {
    if (v1 < 0 || v1 >= numVerticies || v2 < 0 || v2 >= numVerticies)
        throw out_of_range("Vertex index out of range");
    matrix[v1][v2] = w;
	#ifndef DIRECTED_GRAPH
	 matrix[v2][v1] = w;
	#endif
}






