#include <iostream>
#include <fstream>
using namespace std;

/*
Help from:
https://www.youtube.com/watch?v=z0FDBGbf42Q
https://www.youtube.com/watch?v=COZK7NATh4k

Programmer Name: Michael Schloss
Program Name: AVL Tree Builder
Date: 10/10/2019
Assumptions:
 - File must be integers
 - Nodes must be > 0
 - Empty node inputs are either -1 or not included
*/


// No req, this is only node qualities
struct node
{
	int nodeValue;
	node* left;
	node* right;
};
// Node defined

// Also no requirements. This simple builds the node
struct node* newNode(int inNodeValue)
{
	node* node = new struct node;
	node->nodeValue = inNodeValue;
	node->left = NULL;
	node->right = NULL;
	return node;
}
 // Node built

// This is a pointer, pointing to the current node and its child(ren)
// This sets the node's children to NULL until/if filled in
node* CreateNewNode(int nodeValue)
{
	node* newNode = new node();
	newNode->nodeValue = nodeValue;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}
// Node(s) created

// Conditions:
//  - Must have file with inputs following the assumptions
//  - The 1st read integer will be the root
//This takes the numbers from the file and puts them
//into their lexicographical positions.
node* BuildAtree(node* currNode, int nodeValue)
{
	if (currNode == NULL)
	{
		currNode = CreateNewNode(nodeValue);
		return currNode;
	}
	else if (nodeValue <= currNode->nodeValue)
	{
		currNode->left = BuildAtree(currNode->left, nodeValue);
	}
	else
	{
		currNode->right = BuildAtree(currNode->right, nodeValue);
	}
	return currNode;
}
// The tree has been built

//Condition: none
// If the file is empty or only -1, this will return false
// This will read whether the tree is binary or not
bool IsTreeBinary(node* root)
{
	if (root != NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// Is binary? - complete

// Conditions: Follow the assumptions  /  LNR
// This will output the tree nodes in the In-Order Traversal
void PrintInOrder(node* currNode, int nodeValue)
{
	if (currNode != NULL)
	{
		if (currNode->left != NULL && currNode->left->nodeValue != -1)
		{
			PrintInOrder(currNode->left, nodeValue);
		}
		cout << currNode->nodeValue << " ";
		if (currNode->right != NULL && currNode->right->nodeValue != -1)
		{
			PrintInOrder(currNode->right, nodeValue);
		}
	}
	else
	{
		cout << "n/a";
	}
}
// In-Order printed

// Conditions: Follow the assumptions  /  NLR
// This will output the tree nodes in the Pre-Order Traversal
void PrintPreOrder(node* currNode, int nodeValue)
{
	if (currNode != NULL)
	{
		cout << currNode->nodeValue << " ";
		if (currNode->left != NULL && currNode->left->nodeValue != -1)
		{
			PrintPreOrder(currNode->left, nodeValue);
		}
		if (currNode->right != NULL && currNode->right->nodeValue != -1)
		{
			PrintPreOrder(currNode->right, nodeValue);
		}
	}
	else
	{
		cout << "n/a";
	}
}
// Pre-Order printed

// Conditions: Follow the assumptions  /  LRN
// This will output the tree nodes in the Post-Order Traversal
void PrintPostOrder(node* currNode, int nodeValue)
{
	if (currNode != NULL)
	{
		
		if (currNode->left != NULL && currNode->left->nodeValue != -1)
		{
			PrintPostOrder(currNode->left, nodeValue);
		}
		if (currNode->right != NULL && currNode->right->nodeValue != -1)
		{
			PrintPostOrder(currNode->right, nodeValue);
		}
		cout << currNode->nodeValue << " ";
	}
	else
	{
		cout << "n/a";
	}
}
// Post-Order printed


int main()
{
	node* root = NULL;
	ifstream inFile;
	inFile.open("tree.txt");
	int fileNode;
	

	// Conditions: Follow assumptions
	// Reads values from file and calls the function to build the tree
	while (!inFile.eof())
	{
		inFile >> fileNode;
		if (fileNode == -1)
		{
			continue;
		}
		root = BuildAtree(root, fileNode);
	}
	// File read and tree built

	
	// This will output whether or not the tree is binary
	if (IsTreeBinary(root) == true)
	{
		cout << "This is a binary tree" << endl;
	}
	else
	{
		cout << "This is not a binary tree" << endl;
	}
	// Is binary? - printed


	// The following will output the In/Pre/Post order traversals
	cout << "\nPre-Order Traversal: ";
	PrintPreOrder(root, fileNode);
	cout << "\nIn-Order Traversal: ";
	PrintInOrder(root, fileNode);
	cout << "\nPost-Order Traversal: ";
	PrintPostOrder(root, fileNode);
	cout << endl;
	// Traversals printed

	inFile.close();

	return 0;
}