#include "SparseMatrix.h"
#include "Node.h"

SparseMatrix::SparseMatrix()
{
	FrameHead = nullptr;
	colTail = nullptr;
	rowTail = nullptr;
}

SparseMatrix::SparseMatrix(int rows, int cols)
{
	FrameHead = nullptr;
	colTail = nullptr;
	rowTail = nullptr;
	numRows = rows;
	numCols = cols;

	// this makes the first node of -1
	HeaderNode *node = new HeaderNode();
	node->data = -1;
	node->right = nullptr;
	node->down = nullptr;
	FrameHead = node;
	colTail = node;
	rowTail = node;
}

SparseMatrix::~SparseMatrix()
{
	// Node *currNode = head;
	// while (currNode != nullptr)
	// {
	// 	Node *temp = currNode;
	// 	currNode = currNode->;
	// 	delete temp;
	// }
}

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
	HeaderNode *traverser = FrameHead;
	cout << "column nodes:" << endl;
	while (traverser != nullptr)
	{
		cout << traverser->data << endl;
		traverser = traverser->right;
	}

	// this prints out the nodes going down aka the row nodes
	cout << "row nodes:" << endl;
	traverser = FrameHead;
	while (traverser != nullptr)
	{
		cout << traverser->data << endl;
		traverser = traverser->down;
	}
}

void SparseMatrix::InsertInternNode(int row, int col, int val)
{
	// this the hard part
	InternalNode *newNode = new InternalNode(row, col, val);
	HeaderNode *rowIndex = FrameHead;
	HeaderNode *colIndex = FrameHead;

	// move rowIndex and colIndex to where new internal node is to be inserted
	for (int r = 0; r <= row; r++)
	{
		rowIndex = rowIndex->down;
	}
	for (int c = 0; c <= col; c++)
	{
		colIndex = colIndex->right;
	}
	// just a check
	//  cout << rowIndex->data << " " << colIndex->data << endl;

	// now insert the internal node at those indexes
	rowIndex->right = newNode;
	colIndex->down = newNode;
}

void SparseMatrix::PrintInside()
{
	// TODO: print the inside nodes
}
