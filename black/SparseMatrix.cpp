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
	for (int r = 0; r < numRows; r++)
	{
		for (int c = 0; c < numCols; c++)
		{
			cout << "--------------------------------" << endl;
			cout << "r: " << r << " c: " << c << endl
				 << endl;
			InternalNode *newNode = new InternalNode(r, c, 14);
			newNode->PrintInfo();
			cout << endl;
			if (newNode->col == 0 && newNode->row == 0)
			{
				// this is the head of the internal list
				cout << "inserting at head" << endl;
				InternalHead = newNode;
			}
			else if (newNode->row == 0)
			{
				// get the left node and insert/link
				InternalNode *leftNode = GetInternalNode(newNode->row, newNode->col - 1);
				// leftNode = GetInternalNode(newNode->col - 1, newNode->row);
				cout << "left node created" << endl;

				leftNode->right = newNode;
				cout << "new node inserted" << endl;
				newNode->left = leftNode;
				cout << "left node linked" << endl;
				leftNode->PrintInfo();
				cout << endl;
			}
			else if (newNode->col == 0)
			{
				// get the above node and insert/link
				InternalNode *aboveNode = GetInternalNode(newNode->row - 1, newNode->col);
				cout << "Above" << endl;
				// aboveNode = GetInternalNode(newNode->col, newNode->row - 1);
				cout << "above node created" << endl;
				aboveNode->down = newNode;
				cout << "new node inserted";
				newNode->up = aboveNode;
				cout << "above node linked" << endl;
			}
			else
			{
				// get the above node and left node and insert/link
				InternalNode *aboveNode = GetInternalNode(newNode->row - 1, newNode->col);
				InternalNode *leftNode = GetInternalNode(newNode->row, newNode->col - 1);
				cout << "Above and left" << endl;
				cout << "above node and left node created" << endl;
				aboveNode->down = newNode;
				cout << "above node inserted" << endl;
				newNode->up = aboveNode;
				cout << "above node linked" << endl;
				leftNode->PrintInfo();
				leftNode->right = newNode;
				cout << "left node inserted";
				newNode->left = leftNode;
				cout << "left node linked" << endl;
			}
		}
	}
}

void SparseMatrix::PrintFrame()
{
	// this prints out the nodes to the right aka the col nodes
	HeaderNode *traverser = FrameHead->right;
	cout << "column nodes:" << endl;
	while (traverser != nullptr)
	{
		cout << traverser->data << endl;
		traverser = traverser->right;
	}

	// this prints out the nodes going down aka the row nodes
	cout << "row nodes:" << endl;
	traverser = FrameHead->down;
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

void SparseMatrix::PrintInside()
{
	// TODO: print the inside nodes
	InternalNode *traverser = InternalHead;

	// lets just print the first row first
	while (traverser != nullptr)
	{
		traverser->PrintInfo();
	}
}
