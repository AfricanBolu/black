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
	
}

void SparseMatrix::Frame(/* args */) {
	HeaderNode* currRight = head;
	while (currRight != nullptr) {
		HeaderNode* temp = currRight;
		currRight = currRight->getRightNode();
	}
}

void SparseMatrix::InterMatrix(/* args */) {

}
// test test this is gabe
// yeah it working
