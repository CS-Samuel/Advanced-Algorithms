//***************************************************************************
//                                  Project #5a
//                              Name:  Samuel Weems
//                           Course:  CMPS 3013, Fall 17
//                         Professor: Dr. Richard P. Simpson
//                              Date: November 29 2017
//***************************************************************************
//                                  Introduction
//
//	In this part of the project we constructed a Graph Class using an 
//	Adjacency List structure. Each node stores a pair of integers which
//	refers to the node number and weight.
//
//***************************************************************************
//                              Program Complexity
//									  O(n log n)
//
//  Heapify is the limiting factor in this program has the highest complexity.
//
//***************************************************************************
//
//  I have written the entire program as turned in and have not copied this
//  code, or parts of this code from the internet or another student.
//
//                                  Signature _______________________________
//
//***************************************************************************


#include "Graph.h"
#include <iostream>
#include <string>

int main()
{
	string type;
	dtype gtype;
	int numVertices, originVertex, destinationVertex;
	
	cin >> type;
	cin >> numVertices;
	
	if (type == "U")
		gtype = UNDIRECTED;
	else
		gtype = DIRECTED;

	Graph g(numVertices, gtype);

	while (cin >> originVertex)
	{
		cin >> destinationVertex;
		g.AddEdge(originVertex, destinationVertex, 0);
	}

	vector<int> parentVector = g.BFS(5);
	for (auto x : parentVector)
		cout << x << " ";

	cout << endl;

	vector<int> parentVector2 = g.DFS(-1);
	for (auto x : parentVector2)
		cout << x << " ";

	return 0;
}
