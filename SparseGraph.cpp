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

// #ifndef DIRECTED_GRAPH // Directed Graphs

// #ifndef UNDIRECTED_GRAPH // Undirected graph <- in specific implementations in insertEdge and other places


template <class T>
SparseGraph<T>::SparseGraph(int V) {

	list = new AdjecencyListNode* [V];
	for (int i = 0; i < V; i++){
		list [i] = nullptr;
	
	}
}


template <typename T>
SparseGraph<T>::~SparseGraph() {
	
	for (int i = 0; i < this->V; i++) { // looping thru from 0 to num of vertices
	
		AdjencyListNode* current = list[i];
		while (current != nullptr) {
		
			AdjecencyListNode* temp = current;
			current = current-> next;
			delete temp;
		}
	
	delete[] list;
	}


}


template <typename T>
bool SparseGraph<T>::isEdge(int v1, int v2) const {

	AdjecencyListNode* current = list[v1];
	while (current != nullptr) {
	
		if (current->vertex == v2) {
			return true;
		
		}
		current = current->next;
		
	}
	return false;


}

template <typename T>
T SparseGraph<T>::getWeight(int v1, int v2) const {	

	AdjecencyListNode* current = list[v1];
	while (current != nullptr) {
	
		if (current->vertex == v2) {
			return current->weight;
		}
		current = current->next;
	}
	return T();

}


template <typename T>
void SparseGraph<T>::insertEdge(int v1, int v2, T w) {
    AdjecencyListNode* newNode = new AdjecencyListNode(v2, w);
    newNode->next = list[v1];
    list[v1] = newNode;
}





















