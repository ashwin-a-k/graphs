	//===============================================================
// SparseGraph.cpp
// implementation of SparseGraph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>
#include <vector>
#include "SparseGraph.h"

//#ifndef DIRECTED_GRAPH // Directed Graphs

//#ifndef UNDIRECTED_GRAPH // Undirected graph <- in specific implementations in insertEdge and other places


SparseGraph::SparseGraph() : Graph() 
{

}
 
SparseGraph::SparseGraph(int V, int E) : Graph(V, E) 
{
    list.resize(V);
}

SparseGraph::SparseGraph(const SparseGraph& graph) : Graph(mygraph) 
{
    //V = graph-> numVertices;
    //E = graph-> numEdges;
    list = graph.list;
}

SparseGraph::~SparseGraph()
{
		list.clear();
    // No need to explicitly delete nodes, as std::vector handles memory management
}

/*
SparseGraph& SparseGraph::operator=(const SparseGraph& graph) 
{
    if (this != &graph) {
        Graph::operator=(graph);
        //V = graph-> numVertices;
        //E = graph-> numEdges;
        list = graph.list;
    }
    return *this;
}
*/

SparseGraph& SparseGraph::operator=(const SparseGraph& graph)
{
    if (this != graph) {
        list.clear();

        SparseGraph* sg = dynamic_cast<SparseGraph*>(graph);
        if (sg) {
            numVertices = sg->numVertices;
            numEdges = sg->numEdges;
            list = sg->list;
        }
    }
    return *this;
}




bool SparseGraph::isEdge(int v1, int v2) 
{
    for (const auto& node : list[v1]) {
        if (node.vertex == v2) {
            return true;
        }
    }
    return false;
}

int SparseGraph::getWeight(int v1, int v2)
{
    for (const auto& node : list[v1]) {
        if (node.vertex == v2) {
            return node.weight;
        }
    }
    return 0;
}

void SparseGraph::insertEdge(int v1, int v2, int w) 
{
    list[v1].emplace_back(v2, w);
}















