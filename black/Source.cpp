#include "ArgumentManager.h"
#include "SparseMatrix.h"
#include "Matrix.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{ // int argc, char* argv[]) {
	// ArgumentManager am(argc, argv);
	ifstream in("input1.txt");
	ofstream out("output.txt");

	char operations;
	int numRow, numCol;
	int row, col, value;
	string line;

	in >> operations;
	cout << operations << endl;
	in >> numRow >> numCol;
	cout << numRow << " " << numCol << endl;
	in.ignore();

	Matrix m1(numRow, numCol);
	SparseMatrix t1(numRow, numCol);
	t1.PrintFrame();

	while (getline(in, line))
	{
		if (line.length() == 0)
		{
			break;
		}
		// cout << line << endl;
		stringstream ss(line);
		ss >> row >> col >> value;
		cout << row << " " << col << " " << value << endl;
		m1.Insert(row, col, value);
	}

	cout << "--------------------------------\n";
	in >> numRow >> numCol;
	cout << numRow << " " << numCol << endl;
	in.ignore();

	Matrix m2(numRow, numCol);

	while (getline(in, line))
	{
		if (line.length() == 0)
		{
			break;
		}
		// cout << line << endl;
		stringstream ss(line);
		ss >> row >> col >> value;
		cout << row << " " << col << " " << value << endl;
		m2.Insert(row, col, value);
	}

	cout << endl
		 << endl
		 << "First matrix:" << endl;
	m1.Print();
	cout << endl
		 << endl
		 << "Second Matrix:" << endl;
	m2.Print();
	cout << endl
		 << endl;
	Matrix m3 = m1 + m2;
	cout << "Addition:\n";
	m3.Print();
	cout << endl
		 << endl;
	Matrix m4 = m1 * m2;
	cout << "Multiplication:\n";
	m4.Print();
	cout << endl
		 << endl;
	Matrix m5 = m3.transpose();
	cout << "Transpose:\n";
	m5.Print();

	return 0;
}

