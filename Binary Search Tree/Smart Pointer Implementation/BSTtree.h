#pragma once
#include <memory>
#include <iostream>
using namespace std;
class BSTtree
{
	struct Node {
		int val;
		int treeSize;
		shared_ptr<Node> left;
		shared_ptr<Node> right;
		Node() :val(), left(), right() {};
		Node(int v) :val(v), left(), right() {}
		Node(int v, shared_ptr<Node> l, shared_ptr<Node> r):val(v), left(l), right(r) {}
	};

	shared_ptr<Node> root;

	// Private Aux support functions for the public version
	void AuxInsert(shared_ptr<Node>&, int);
	void AuxInorder(shared_ptr<Node>);
	void AuxDelete(shared_ptr<Node>& r, int n);
	shared_ptr<Node> Copy(const shared_ptr<Node>&);
    
    //HW1 int SumNodes();//return the sum of the values in the tree;
    
    int SumNodesAux(shared_ptr<Node>& r);
    
    //HW2 int Height();//Return the height of the tree;
    
    int HeightAux(shared_ptr<Node>& r);
    
    
public:
	BSTtree();// default constructor
	BSTtree(initializer_list<int> lst);// constructor using init list
	~BSTtree();// nothing goes on here
	void Insert(int n);// insert a new node in the tree
	void InorderPrint();// Print the tree via an inorder traversal
	void Delete(int v);// delete value v from the tree.

	BSTtree(const BSTtree&);// This the the ususal copy constructor
	BSTtree(BSTtree&&)=default;//This is the move constructor. Uses default so we dont
	                           // need to implement it. Of course we can't debug into it.
							
	BSTtree& operator=(const BSTtree &); // Normal overloaded assignment
	BSTtree& operator=(BSTtree&&);// move assignment

	////////////////////////////////////////////////////////////////////////
	//Fun methods for you to implement
    ///////////////////////////////////////////////////////////////////////
	//int NumNodes();//Return the number of nodes in the tree

	//HW1 int SumNodes();//return the sum of the values in the tree;
    
    int SumNodes();

	//HW2 int Height();//Return the height of the tree;
    
    int Height();

	//HW3 void DeleteRoot();//delete the root of the tree;
    
    void DeleteRoot();

	//void DeleteMin();// delete the smallest node in the tree;

	//HW4 void InsertNR(int x);
    
    void InsertNR(int x);

	//hw5 Depth(int v);// Do non recursively
    
    int Depth(int v);

	//void RotateLeft(); // Insert root in left subtree and replace the root with the smallest
	                     // node in the right subtree.

	//Augument the tree node with a new variable size; This will be used to store
	// the number of nodes in the tree rooted at that node. Modify the insert and delete
	// so that this variable is correctly maintained.

	//void Rotate();//have this do a rotate from the large subtree to the small side. You
	// can now use size to decide which way to rotate. 

	//int IPL(); //Return the internal path length of the tree. This is the sum of the depths
	//          of every node in the tree.

	//BSTtree Balance(const BSTtree &);// Balance the tree sent in by loading into a vector
	//       and then constructing the tree recursively from the vector. Now return this new
	//       tree.  ie middle is inserted first, middle of leftside second, middle of rightside
	//       and so on.

};

