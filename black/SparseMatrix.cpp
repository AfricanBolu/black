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
	// 	 << "it fucking worked ayyayayayay" << endl;
}

void SparseMatrix::MakeInternal()
{

	InternalNode *head = new InternalNode(-1, -1, -1); // Head node
	InternalNode *prevRow = head;					   // Pointer to previous row
	InternalNode *prevCol[numCols];					   // Array of pointers to previous column

	// Initialize previous column pointers to head
	for (int i = 0; i < numCols; i++)
	{
		prevCol[i] = head;
	}

	// Create nodes for each element and link them
	for (int i = 0; i < numRows; i++)
	{
		InternalNode *currRow = new InternalNode(i, -1, -1); // Pointer to current row
		prevRow->down = currRow;
		currRow->up = prevRow;
		prevRow = currRow;

		InternalNode *currCol = nullptr; // Pointer to current column

		for (int j = 0; j < numCols; j++)
		{
			int val;
			// Get value from user input or generate random value
			cout << "Enter value for row " << i << ", column " << j << ": ";
			cin >> val;
			// val = rand() % 10 + 1; // Uncomment this line to generate random value

			currCol = new InternalNode(-1, j, val); // Pointer to current column
			prevCol[j]->right = currCol;
			currCol->left = prevCol[j];
			currCol->up = prevCol[j]->up->right;
			// currCol->up->down = currCol;
			// prevCol[j]->up->right = currCol;
			// currCol->down = prevCol[j]->down->right;
			// prevCol[j]->down->right = currCol;
			// prevCol[j] = currCol;
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
