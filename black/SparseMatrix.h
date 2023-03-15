#pragma once
#include "Node.h"

class SparseMatrix
{
private:
	Node *head;
	Node *tail;
	int value;
	int size;

public:
	SparseMatrix();
	~SparseMatrix();
	void Frame(int numRows, int numCols);
	void InterMatrix(/* args */);
};

SparseMatrix::SparseMatrix()
{
	head = nullptr;
	tail = nullptr;
}

SparseMatrix::~SparseMatrix()
{
	// worry about this shit later i just wanna get the frame working
	//  Node *currNode = head;
	//  while (currNode != nullptr)
	//  {
	//  	Node *temp = currNode;
	//  	currNode = currNode->;
	//  	delete temp;
	//  }
}

void SparseMatrix::Frame(int numRows, int numCols)
{
}

void SparseMatrix::InterMatrix(/* args */)
{
}
