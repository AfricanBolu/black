#pragma once
#include <iostream>

using namespace std;

class Matrix {
public:
	Matrix(int, int);
	~Matrix();
	void Insert(int, int, int);
	void Print();
	Matrix operator+(const Matrix& rhs);
	Matrix operator*(const Matrix& rhs);
	Matrix transpose();
private:
	int numRows, numCols;
	int** values;
};
