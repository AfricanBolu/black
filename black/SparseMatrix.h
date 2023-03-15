#pragma once
#include "Node.h"

class SparseMatrix
{
private:
	Node *head;
	Node *tail;
	// does this class really need an int value? the values should all be stored in the nodes right?
	int value;
	int size;
	int numRows;
	int numCols;

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
	Node *currNode = head;
	while (currNode != nullptr)
	{
		Node *temp = currNode;
		currNode = currNode->;
		delete temp;
	}
}

void SparseMatrix::Frame(int numRows, int numCols)
{
}

void SparseMatrix::InterMatrix(/* args */)
{
}
