#pragma once
#include "Node.h"



class SparseMatrix
{
private:
	HeaderNode* head;
	int value;
	int size;
public:
	SparseMatrix(/* args */);
	~SparseMatrix();
	void Frame(/* args */);
	void InterMatrix(/* args */);
};

SparseMatrix::SparseMatrix(/* args */)
{
}

SparseMatrix::~SparseMatrix()
{
	HeaderNode* currRow = head;
	while (currRow != NULL) {
		HeaderNode* temp = currRow;
		currRow = currRow.getRight();

	}

}

void SparseMatrix::Frame(/* args */) {

}

void SparseMatrix::InterMatrix(/* args */) {

}
// test test this is gabe
// yeah it working
