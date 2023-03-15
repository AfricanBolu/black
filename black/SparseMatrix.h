#pragma once
#include "Node.h"

class SparseMatrix
{
private:
	HeaderNode *head;
	HeaderNode *colTail; // this tail is the end of the nodes going right
	HeaderNode *rowTail; // this tail is the end of the nodes going down
	int value;			 // ohh if this is meant to be the values of the internal nodes then maybe we should make it a 2d array
	int numRows;
	int numCols;

public:
	SparseMatrix();
	SparseMatrix(int rows, int cols);
	~SparseMatrix();
	void Frame();
	void PrintFrame();
	void InterMatrix(/* args */);
};

SparseMatrix::SparseMatrix()
{
	head = nullptr;
	colTail = nullptr;
	rowTail = nullptr;
}

SparseMatrix::SparseMatrix(int rows, int cols)
{
	head = nullptr;
	colTail = nullptr;
	rowTail = nullptr;
	numRows = rows;
	numCols = cols;

	// this makes the first node of -1
	HeaderNode *node = new HeaderNode();
	node->data = -1;
	node->right = nullptr;
	node->down = nullptr;
	head = node;
	colTail = node;
	rowTail = node;
}

// just so that main works
//  SparseMatrix::~SparseMatrix()
//  {
//  	Node *currNode = head;
//  	while (currNode != nullptr)
//  	{
//  		Node *temp = currNode;
//  		currNode = currNode->;
//  		delete temp;
//  	}
//  }

void SparseMatrix::Frame()
{
	// for loop to make col nodes to the right
	for (int i = 0; i < numCols; i++)
	{
		HeaderNode *node = new HeaderNode();
		node->data = i;
		node->right = nullptr;
		node->down = nullptr;
		colTail->right = node;
		colTail = node;
	}

	// for loop to make row nodes going down
	for (int i = 0; i < numRows; i++)
	{
		HeaderNode *node = new HeaderNode();
		node->data = i;
		node->right = nullptr;
		node->down = nullptr;
		rowTail->down = node;
		rowTail = node;
	}
}

void SparseMatrix::PrintFrame()
{
	// this prints out the nodes to the right aka the col nodes
	HeaderNode *traverser = head;
	while (traverser != nullptr)
	{
		cout << traverser->data << endl;
		traverser = traverser->right;
	}

	// this prints out the nodes going down aka the row nodes
	Node *traverser = head;
	while (traverser != nullptr)
	{
		cout << traverser->data << endl;
		traverser = traverser->down;
	}
}

void SparseMatrix::InterMatrix(/* args */)
{
}
