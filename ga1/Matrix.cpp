#include "Matrix.h"
void Matrix::Print() {
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			cout << values[row][col] << " ";
		}
		cout << endl;
	}
}

void Matrix::Insert(int row, int col, int value) {
	values[row][col] = value;
}

Matrix Matrix::operator+(const Matrix& rhs) {
	//ToDo: check size of the matrices	
	Matrix result(numRows, numCols);
	int sum;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			sum = values[row][col] + rhs.values[row][col];
			result.Insert(row, col, sum);
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& rhs) {
	Matrix result(numRows, numCols);
	int sum;
	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			sum = 0;
			for (int total = 0; total < numCols; total++) {
				sum += values[row][total] * rhs.values[total][col];
			}
			result.Insert(row, col, sum);
		}
	}
	return result;
}

Matrix Matrix::transpose() {
	Matrix result(numCols, numRows);
	int temp;
	for (int row = 0; row < numCols; row++) {
		for (int col = 0; col < numRows; col++) {
			temp = values[col][row];
			result.Insert(col, row, temp);
		}
	}
	return result;
}

Matrix::Matrix(int nRows, int nCols) {
	numRows = nRows;
	numCols = nCols;

	values = new int*[numRows];
	for (int i = 0; i < numRows; i++) {
		values[i] = new int[numCols];
	}

	for (int row = 0; row < numRows; row++) {
		for (int col = 0; col < numCols; col++) {
			values[row][col] = 0;
		}
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < numRows; i++) {
		delete[] values[i];
	}
	delete[] values;
}

