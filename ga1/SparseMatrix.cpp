#include "SparseMatrix.h"
#include "Node.h"
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix()
{
	InternalHead = nullptr;
	FrameHead = nullptr;
	colTail = nullptr;
	rowTail = nullptr;
	numRows = 0;
	numCols = 0;
	value = 0;
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

	// assign internHead to position (0,0) inside the matrix
	InternalNode *internHead = new InternalNode(0, 0, 0);
	HeaderNode *col = FrameHead;
	HeaderNode *row = FrameHead;

	col = col->right;
	row = row->down;

	col->down = internHead;
	row->right = internHead;

	InternalHead = internHead;

	// just a check for internal head
	// cout << InternalHead->data << endl
}

InternalNode *SparseMatrix::GetInternalNode(int row, int col)
{
	if (row < 0 || row >= numRows || col < 0 || col >= numCols)
		cout << "Error in GetInternalNode" << endl;

	InternalNode *node = InternalHead;

	for (int i = 0; i < row; i++)
	{
		node = node->down;
	}
	for (int j = 0; j < col; j++)
	{
		node = node->right;
	}
	// dynamic_cast<framenode*>(header)
	// InternalNode* temp = dynamic_cast<InternalNode*>(node);
	return node;
}

void SparseMatrix::MakeInternal()
{
	// InternalNode *leftNode;
	// InternalNode *aboveNode;

	// Create nodes for each element and link them
	// int count = 0;
	for (int r = 0; r < numRows; r++)
	{
		for (int c = 0; c < numCols; c++)
		{
			// cout << "--------------------------------" << endl;
			// cout << "r: " << r << " c: " << c << endl << endl;
			InternalNode *newNode = new InternalNode(r, c, 0);
			// newNode->PrintInfo();
			// cout << endl;
			if (newNode->col == 0 && newNode->row == 0)
			{
				// this is the head of the internal list
				// cout << "inserting at head" << endl;
				InternalHead = newNode;
			}
			else if (newNode->row == 0)
			{
				// get the left node and insert/link
				InternalNode *leftNode = GetInternalNode(newNode->row, newNode->col - 1);
				// leftNode = GetInternalNode(newNode->col - 1, newNode->row);
				// cout << "left node created" << endl;

				leftNode->right = newNode;
				// cout << "new node inserted" << endl;
				newNode->left = leftNode;
				// cout << "left node linked" << endl;/
				// leftNode->PrintInfo();
			}
			else if (newNode->col == 0)
			{
				// get the above node and insert/link
				InternalNode *aboveNode = GetInternalNode(newNode->row - 1, newNode->col);
				// cout << "Above" << endl;
				// aboveNode = GetInternalNode(newNode->col, newNode->row - 1);
				// cout << "above node created" << endl;
				aboveNode->down = newNode;
				// cout << "new node inserted";
				newNode->up = aboveNode;
				// cout << "above node linked" << endl;
			}
			else
			{
				// get the above node and left node and insert/link
				InternalNode *aboveNode = GetInternalNode(newNode->row - 1, newNode->col);
				InternalNode *leftNode = GetInternalNode(newNode->row, newNode->col - 1);
				// cout << "Above and left" << endl;
				// cout << "above node and left node created" << endl;
				aboveNode->down = newNode;
				// cout << "above node inserted" << endl;
				newNode->up = aboveNode;
				// cout << "above node linked" << endl;
				// leftNode->PrintInfo();
				leftNode->right = newNode;
				// cout << "left node inserted";
				newNode->left = leftNode;
				// cout << "left node linked" << endl;
			}
			// count++;
		}
	}
}

void SparseMatrix::PrintFrame(ostream& out)
{
	// this prints out the nodes to the right aka the col nodes
	HeaderNode *traverser = FrameHead->right;
	cout << "column nodes:" << endl;
	while (traverser != nullptr)
	{
		out << traverser->data << endl;
		traverser = traverser->right;
	}

	// this prints out the nodes going down aka the row nodes
	cout << "row nodes:" << endl;
	traverser = FrameHead->down;
	while (traverser != nullptr)
	{
		out << traverser->data << endl;
		traverser = traverser->down;
	}
}

void SparseMatrix::InsertInternNode(int row, int col, int val)
{
	// this the hard part
	InternalNode *newNode = new InternalNode(row, col, val);
	HeaderNode *rowIndex = FrameHead;
	HeaderNode *colIndex = FrameHead;

	// if pos(0,0) then that's just the internal head
	if (row == 0 && col == 0)
	{
		InternalHead = newNode;
		return;
	}

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
void SparseMatrix::ChangeValue(int row, int col, int val)
{
	// this is the hard part
	// InternalNode *newNode = new InternalNode(row, col, val);
	InternalNode *traverser = InternalHead;

	// if pos(0,0) then that's just the internal head
	if (row == 0 && col == 0)
	{
		InternalHead->data = val;
		return;
	}

	// traverse to the internal node that is to be changed
	for (int r = 0; r < row; r++)
	{
		traverser = traverser->down;
	}
	for (int c = 0; c < col; c++)
	{
		traverser = traverser->right;
	}
	traverser->data = val;
}

void SparseMatrix::PrintInside(ostream& out)
{
	// TODO: print the inside nodes
	InternalNode *traverser = new InternalNode(0, 0, 0);

	// lets just print the first row first
	for (int r = 0; r < numRows; r++)
	{
		// cout << "row: " << r << endl;
		traverser = GetInternalNode(r, 0);
		while (traverser != nullptr)
		{
			if (traverser->right == nullptr)
			{
				cout << traverser->data << endl;
				break;
			}
			out << traverser->data << ", ";
			traverser = traverser->right;
		}
	}
}

SparseMatrix SparseMatrix::operator+(SparseMatrix& rhs) {
	SparseMatrix result(numRows, numCols);
	InternalNode *sum;
	InternalNode* rhsCurr;
	result.MakeInternal();

	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			sum = GetInternalNode(r, c);
			rhsCurr = rhs.GetInternalNode(r, c);
			result.ChangeValue(r, c, sum->data + rhsCurr->data);
		}
	}

	return result;
}

SparseMatrix SparseMatrix::operator*(SparseMatrix& rhs) {
	SparseMatrix result(numRows, numCols);
	result.MakeInternal();
	
	/*InternalNode* temp2;
	InternalNode* temp3;*/

	for (int r = 0; r < numRows; r++) {
		for (int c = 0; c < numCols; c++) {
			int temp2 = 0;
			for (int t = 0; t < numCols; t++) {
				InternalNode* multi = GetInternalNode(r, t);
				InternalNode* temp = rhs.GetInternalNode(t, c);
				temp2 += multi->data * temp->data;
			}
			result.ChangeValue(r, c, temp2);
		}
	}

	return result;
}



SparseMatrix SparseMatrix::transpose() {
	SparseMatrix result(numCols, numRows);
	InternalNode* ogNode;
	result.MakeInternal();
	for (int r = 0; r < numCols; r++) {
		for (int c = 0; c < numRows; c++) {
			ogNode = GetInternalNode(r, c);
			if (ogNode != nullptr) {
				result.ChangeValue(c, r, ogNode->data);
			}
		}
	}
	return result;
}

