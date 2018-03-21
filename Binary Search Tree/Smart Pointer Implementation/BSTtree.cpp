#include "BSTtree.h"

BSTtree::BSTtree()
{
	root = nullptr;
}


BSTtree::~BSTtree()
{
}

void BSTtree::Insert(int n)
{
	AuxInsert(root, n);
}

// Private recursive insert.
void BSTtree::AuxInsert(shared_ptr<Node>& r, int n)
{
	if (!r) {
		// Construct a new node when you find a nullptr at the
		// bottom of the tree.
		r = make_shared<Node>(Node(n));
	}
	else {
		if (n < r->val)
			AuxInsert(r->left, n);
		else
			AuxInsert(r->right, n);
	}
}

// print the tree
void BSTtree::InorderPrint()
{
	if (!root)
		cout << "Empty tree" << endl;
	AuxInorder(root);
}

// Private recursive traversal
void BSTtree::AuxInorder(shared_ptr<Node> r)
{
	if (r) {// pointer is not nullptr
		AuxInorder(r->left);
	    cout << r->val << " ";
		AuxInorder(r->right);
	}
}

// searches for v in tree and removes it.
void BSTtree::Delete(int v)
{
	if (!root) {
		cout << "ERROR: Tree is empty!" << endl;
		return;// object tree is null so return
	}
	AuxDelete(root, v);
}


// Private recursive delete. Note that we must have the & here
// so modified r's will be set correctly
void BSTtree::AuxDelete(shared_ptr<Node>& r, int n)
{
	shared_ptr<Node> fd;// this will point to fd node
	// first we find the node if it exists.
	if (!r)return;// parameter tree is null so return
	if (n < r->val)
		AuxDelete(r->left,n);
	else if (n > r->val)
		AuxDelete(r->right,n);
	else if (n == r->val) {// we have found it
		fd = r;// this is the found node
		// complicated part.  There are three cases
		if (!r->left && !r->right) {//Case 1: no childern
			r = nullptr; // This will auto destruct the node that r points at
			return;
		}
		else {// Case 2: only one child
			if (r->left && !r->right) {// right child missing
				r = r->left;// splice it out. It will auto destruct the spliced out node
				return;
			}
			else {
				if (!r->left && r->right) {//left child missing
					r = r->right; // splice it out. Will auto destruct the spliced out node
					return;
				}
				else {// we have both children. Here we will replace with successor
					// go right one. Don't change r here !!
					shared_ptr<Node> fd,tmp;// this will point to fd node
					fd = r;// save our found node
					tmp= r->right;// use a tmp pointer so we will not corrupt r
					// if this node has no left node the splice it out 
					if (!tmp->left) {
						fd->val = tmp->val;
						fd->right = tmp->right;
						return;
					}
					// go all the way to the left and stop on the last node
					// tmp will now point to the successor node
					shared_ptr<Node> f;// this pointer follows tmp
					while (tmp->left) {
						f = tmp;
						tmp = tmp->left;
					}
					fd->val = tmp->val;// copy successors value to fd node
					f->left = tmp->right;// splice out node
					return; 
				}
			}
		}

	}

}

// This the the ususal copy constructor
BSTtree::BSTtree(const BSTtree& t)
{
	root = Copy(t.root);
}

// Recursively builds a copy of the tree pointed to by r
shared_ptr<BSTtree::Node> BSTtree::Copy(const shared_ptr<Node>& r)
{
	shared_ptr<Node> rt=nullptr;
	if (r) {
		// create new node
		rt = make_shared<Node>(Node(r->val,Copy(r->left),Copy(r->right)));
	}
	return rt;
}


// Normal overloaded assignment
BSTtree& BSTtree::operator=(const BSTtree & t)
{
	if (root != t.root) {// not copying onto myself ie A=A
		root = Copy(t.root);// create a new tree and put it into root
	}
	return *this;
}

// Initializer_list constructor
BSTtree::BSTtree(initializer_list<int> lst)
{
	for (auto i : lst) {
		Insert(i);
	}
}
// This is the same as the default move assignment
// I could have defaulted it in the .h file and left this
// out.  I included it in this case so you can see that
// it actually gets called when we have a rvalue parameter
BSTtree& BSTtree::operator=(BSTtree&& r) {// move assignment
	swap(root, r.root);
    // when this returns the original root tree gets destroyed
	// automatically by the calling syntax 
	return *this;
}


//HW1 int SumNodes();//return the sum of the values in the tree;

int BSTtree::SumNodes()
{
    return SumNodesAux(root);
}

int BSTtree::SumNodesAux(shared_ptr<Node>& r)
{
    if (!r)
        return 0;
    return (r->val + SumNodesAux(r-> left) + SumNodesAux(r->right));
}



//HW2 int Height();//Return the height of the tree;

int BSTtree::Height()
{
    if (!root)
        return 0;
    else
        return HeightAux(root);
}

int BSTtree::HeightAux(shared_ptr<Node>& r)
{
    int leftHeight = 0, rightHeight = 0, currentHeight;
    
    if (r->left != nullptr)
        leftHeight = HeightAux(r->left);
    if (r->right != nullptr)
        rightHeight = HeightAux (r->right);
    
    if (leftHeight > rightHeight)
        currentHeight = leftHeight;
    else
        currentHeight = rightHeight;
    
    return 1 + currentHeight;
}

//HW3 void DeleteRoot();//delete the root of the tree;

void BSTtree::DeleteRoot()
{
    AuxDelete(root, root->val);
}


//HW4 void InsertNR(int x);
// Non Recursive insert function

void BSTtree::InsertNR(int x)
{
    if (!root)
        root = make_shared<Node>(Node(x));
    else{
    shared_ptr<Node> current = root;
    shared_ptr<Node> previous = nullptr;
    
    while (current != nullptr)
    {
        previous = current;
        if (x > current->val)
            current = current -> right;
        else
            current = current -> left;
    }
    
    if (x > previous->val)
        previous->right = make_shared<Node>(Node(x));
    else
        previous->left = make_shared<Node>(Node(x));
    }

}



int BSTtree::Depth(int v)
{
    int depth = 0;
    
    if (!root)
        return -1;
    
    shared_ptr<Node> temp;
    temp = root;
    
    while (temp != nullptr && temp->val != v)
    {
      
        if (v > temp->val)
        {
            temp = temp -> right;
            ++depth;
        }
        
        if (v < temp->val)
        {
            temp = temp ->left;
            ++depth;
        }
    }
    
    if (temp == nullptr)
        return -1;
    
    return depth;
}
