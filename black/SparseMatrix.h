#pragma once
#include "Node.h"

class SparseMatrix
{
private:
	Node *head;
	Node *tail;
	// does this class really need an int value? the values should all be stored in the nodes right?
	//i think it does so we can tell it what the current value is to save the location i think
	int value;
	int size;
	int numRows;
	int numCols;

public:
	SparseMatrix();
	~SparseMatrix();
	void Frame(int , int);
	void InterMatrix(/* args */);
};
