#pragma once
#include "Node.h"
#include <ostream>

class SparseMatrix
{
private:
	// HeaderNode *head;
	InternalNode *InternalHead;
	/*InternalNode* cols;
	InternalNode* rows;*/
	HeaderNode *FrameHead;
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
	void MakeInternal();
	void PrintFrame(ostream& out);
	void InsertInternNode(int row, int col, int val);
	void PrintInside(ostream& out);
	InternalNode *GetInternalNode(int row, int col);
	void ChangeValue(int row, int col, int val);
	// please work

	SparseMatrix operator+(SparseMatrix& rhs);
	SparseMatrix operator*(SparseMatrix& rhs);
	SparseMatrix transpose();
};
