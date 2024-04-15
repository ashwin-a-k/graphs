//===============================================================
// Graph.h
// Header file of Graph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

using namespace std;
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
			Graph			(void);
			Graph			(int V, int E);
			Graph			(Graph * mygraph);
virtual 		~Graph			(void) = 0;
virtual	Graph&	operator=		( Graph * mygraph) = 0;
virtual	bool	isEdge			(int v1, int v2) = 0;
virtual	int	getWeight		(int v1, int v2) = 0;
virtual	void	insertEdge		(int v1, int v2, int w) = 0;
friend std::istream& operator>>(std::istream& input, Graph& graph);
friend std::ostream& operator<<(std::ostream& os, const Graph& graph);

		// newly added algorithms: BFS
		void 	BFS 			( int source );
		void	printBFSTable		( int source );
		void 	printBFSPath		( int s, int d);
		void	printMostDistant	( int s );
		bool	isConnected		( void );
		
		//newly added algorithms: DFS
		void 	DFS			( void );
		void	DFS_Visit		( int v, int &clock);
		void	printDFSTable		( void );
		//void	printTopologicalSort	( void ); // don't have to get fully right
		void	printDFSParethesization( void );
		void 	Graph::DFSParethesizationHelper(int v, std::vector<bool> visit, 
								std::string& parenth)
		void 	classifyDFSEdges	( void );
		//void	indexSort		( std::vector<int>& a );
		

protected:
	int numVerticies;
	int numEdges;
	
	enum Color {WHITE, GRAY, BLACK};
	
	struct Vertex
	{
		Color color;
		int fTime;
		int dTime;
		Vertex* pi;
		int d;
		bool visited;
		std::vector<Vertex> vertices;
		std::vector<std::vector<int>> adjList
		
		/*
		Vertex() 
		{
			COLOR = WHITE;
			dTime = 0;
			fTime = 0;
			d = INT_MAX;
			pi = NULL;
			visited = false;
			
		}*/
	}


	
};

#endif
	

