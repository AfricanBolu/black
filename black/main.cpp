// #include "ArgumentManager.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Matrix.cpp"
#include "SparseMatrix.cpp"

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

    SparseMatrix sparse(numRow, numCol);
    sparse.Frame();
    cout << endl
         << "Frame of sparse matrix:" << endl;
    sparse.PrintFrame();
    // sparse.InsertInternNode(0, 1, 2);
    // sparse.InsertInternNode(0, 2, 4);
    // sparse.InsertInternNode(0, 3, 6);

    return 0;
}