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

<<<<<<< HEAD
class DenseGraph : public Graph { //example of how inheritance works
public:
				
			DenseGraph	( void );
			DenseGraph	(int V, int E);
 			~DenseGraph	(void);
			DenseGraph	(Graph * graph1);
	DenseGraph&	operator=	(Graph * graph1);
	bool		isEdge		(int v1, int v2);
	int		getWeight	(int v1, int v2);
	void		insertEdge	(int v1, int v2, int w);
   /*friend istream& operator >> ( istream& input, Graph * graph)
   {
   	return input;
   }
   friend ostream& operator << ( ostream& os, Graph * graph)
   {
   	return os;
   }*/
=======
>>>>>>> e8833085f33fe7c34a39e5bdb36d9f9ed24ac329
private:
    std::vector<std::vector<int>> matrix; 
};
