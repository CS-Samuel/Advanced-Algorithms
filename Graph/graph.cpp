#include "Graph.h"
#include <iostream>

//***************************************************************************
//						Class Graph Method: DPS_Visit
//					    Parameters: int u, vector<int> &parentArray
//							  Returns: None
//						  Complexity: O(V+E)
//
// Private recursive method that does a depth first traversal of the Graph
// exploring down each path before backtracking. The parentArray is passed
// by reference to update the results as they are discovered (WHITE). The 
// complexity is equal to the sum of the vertices and edges.
// 
//***************************************************************************


void Graph::DFS_Visit(int u, vector<int> &parentArray)
{
	Color[u] = GREY;
	
	for (auto v : G[u]) // v is a pair, remember
	{
		if (Color[v.first] == WHITE)
		{
			DFS_Visit(v.first, parentArray);
			parentArray[v.first] = u;

		}
	}

	Color[u] = BLACK;
}

//***************************************************************************
//					  Class Graph Method: Graph
//				 Parameters: int size, dtype type
//							  Returns: None
//						  Complexity: O(1)
//
// Constructor that initializes sizes of vectors and type of graph (either
// directed or undirected).
// 
//***************************************************************************

Graph::Graph(int size, dtype type)
{
	dir = type;
	G.resize(size);
	Color.resize(size);
}

//***************************************************************************
//					  Class Graph Method: AddEdge
//				 Parameters: int from, int to, int wt
//							  Returns: None
//						  Complexity: O(1)
//
// Adds a new edge from one vertex to another with given weight. If the graph
// is undirected then a second return edge is added so that vertices are 
// connected bidirectionally. 
// 
//***************************************************************************

void Graph::AddEdge(int from, int to, int wt)
{
	G[from].push_back({ to,wt });

	if (dir == UNDIRECTED)
		G[to].push_back({ from,wt });
}

//***************************************************************************
//					  Class Graph Method: BFS
//						Parameters: int s
//						  Returns: vector<int>
//						  Complexity: O(V+E)
//
// BFS performs a breadth-first search of the graph. A source vertex (s)
// is passed to be the root and then the as the children are discovered they
// are added to the vector which is returned.
// 
//***************************************************************************

vector<int> Graph::BFS(int s)
{

	// Note the rows of G are vector<pairs> where each pair is <node#,wt>
	int u;
	queue<int> Q;

	for (int i = 0; i < Color.size(); i++)
		Color[i] = WHITE;

	vector<int> Parent(G.size(), -1);// parent array
	Q.push(s);

	while (!Q.empty()) 
	{
		u = Q.front(); Q.pop();
		for (auto v : G[u]) // v is a pair, remember
			if (Color[v.first] == WHITE)
			{
				Color[v.first] = GREY;// in queue now
									  //v->d = u->d + 1;
									 // use this if we need depth knowledge. Would need a depth vector as well
				Parent[v.first] = u;
				Q.push(v.first);
			}
		Color[u] = BLACK;// out ouf queue now
	}
	return Parent;
}


//***************************************************************************
//					  Class Graph Method: DFS
//						Parameters: int s
//						  Returns: vector<int>
//						  Complexity: O(V+E)
//
// DFS does a depth first search calling DPS_Visit (described above). If the
// parameter s is given as -1 then all nodes are checked, otherwise the value
// of s is assumedto be the initial vertex to begin the depth first search.
// 
//***************************************************************************

vector<int> Graph::DFS(int s)
{
	vector<int> Parent(G.size(), -1);// parent array

	for (int i = 0; i < Color.size(); i++)
		Color[i] = WHITE;

	if (s == -1)
	{
		for (int i = 0; i < G.size(); i++)
		{
			if (Color[i] == WHITE)
				DFS_Visit(i, Parent);
		}
	}
	else
		DFS_Visit(s, Parent);

	return Parent;
}
