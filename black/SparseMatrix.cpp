#include "SparseMatrix.h"

SparseMatrix::SparseMatrix()
{
	head = nullptr;
	tail = nullptr;
}

SparseMatrix::~SparseMatrix()
{

}

void SparseMatrix::Frame(int numRows, int numCols) {
	HeaderNode* currRight = head;
	while (currRight != nullptr) {
		HeaderNode* temp = currRight;
		currRight = currRight->getRightNode();
	}
	Node* currNode = head;
	/*while (currNode != nullptr)
	{
		Node *temp = currNode;
		currNode = currNode->;
		delete temp;
	}*/
}

void SparseMatrix::Frame(int numRows, int numCols)
{
}

void SparseMatrix::InterMatrix(/* args */)
{
}
