//===============================================================
// Graph.h
// Header file of Graph class
// Name: Ashwin Krishnamurthy, Tanvi Shegaonkar, Dipanker Thapa
// April 2024
//===============================================================

#include <vector>
#include <iostream>
#include <climits>

#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
					Graph			(void);
					Graph			(int V, int E);
					Graph			(const Graph& mygraph);
					Graph&	operator=		(const Graph& mygraph);
		 		   ~Graph			(void);
				 	
				 	
virtual	bool	isEdge			(int v1, int v2) = 0;
virtual	int	getWeight		(int v1, int v2) = 0;
virtual	void	insertEdge		(int v1, int v2, int w) = 0;


friend std::istream& operator>>(std::istream& input, Graph& mygraph) 
{
     int v1, v2, w;
     for (int i = 0; i < mygraph.numEdges; ++i) {
         input >> v1 >> v2 >> w;
         mygraph.insertEdge(v1, v2, w);
     }
   return input;
 }

friend std::ostream& operator<<(std::ostream& os, const Graph& mygraph) {
	os <<"G = ("<< mygraph.numVertices << ","<< mygraph.numEdges <<")\n";
    /* for (int i = 0; i < graph.list.size(); ++i) {
         os << i << ": ";
         for (const auto& node : graph.list[i]) {
             os << "(" << node.vertex << ", " << node.weight << ") ";
         }
         os << std::endl;
     }
    */
     return os;
 }



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
		//void	printTopologicalSort	( void ); // told to skip
		void	printDFSParethesization( void );
		void 	DFSParethesizationHelper(int v, std::vector<bool> visit,std::string& parenth);
		void 	classifyDFSEdges	( void );
		//void	indexSort		( std::vector<int>& a );
		

protected:
	int numVertices;
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
		std::vector<std::vector<int>> adjList;
		
	};


	
};

#endif
	

