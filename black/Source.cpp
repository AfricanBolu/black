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
    ifstream fin("input2.txt");
    ofstream out("output.txt");

    char operations;
    int numRow1, numCol1, row, col, value;
    string line;

    fin >> operations;
    fin >> numRow1 >> numCol1;
    fin.ignore();

    Matrix m1(numRow1, numCol1);
    //Matrix t0(numRow1, numCol1);
    SparseMatrix s1(numRow1, numCol1);
    s1.MakeInternal();

    while (getline(fin, line))
    {
        if (line.length() == 0)
        {
            break;
        }
        // cout << line << endl;
        stringstream ss(line);
        ss >> row >> col >> value;
        // cout << row << " " << col << " " << value << endl;
        m1.Insert(row, col, value);
        s1.ChangeValue(row, col, value);
    }

    cout << "First matrix:" << endl;
    m1.Print();
    cout << endl;
    s1.PrintInside();

    if (operations == 'T')
    {
        // create a new sparse matrix and deadass just flip the numrows and numcols and transfer the values
        cout << "\noperation t\n";
         SparseMatrix sT(numCol1, numRow1);
         sT = s1.transpose();
         sT.PrintInside();
        return 0;
    }

    cout << "\n--------------------------------\n\n";

    int numRow2, numCol2;
    fin >> numRow2 >> numCol2;
    fin.ignore();


   
    //Matrix t6(numRow2, numCol2);
    Matrix m2(numRow2, numCol2);
    SparseMatrix s2(numRow2, numCol2);
    s2.MakeInternal();
    

    while (getline(fin, line))
    {
        if (line.length() == 0)
        {
            break;
        }
        stringstream ss(line);
        ss >> row >> col >> value;
        // cout << row << " " << col << " " << value << endl;
        m2.Insert(row, col, value);
        s2.ChangeValue(row, col, value);
    }

    cout << "Second Matrix:" << endl;
    m2.Print();
    cout << endl;
    s2.PrintInside();

    if (operations == '+')
    {
        if (numRow1 != numRow2 || numCol1 != numCol2)
        {
            cout << "Invalid Matrix Operation" << endl;
            return 0;
        }
        // do the addition of both matrices
        cout << "\noperation +\n\n";
        s1.PrintInside();
        cout << "\n+\n\n";
        s2.PrintInside();
        cout << "\n=\n\n";
        SparseMatrix sPlus = s1 + s2;

        sPlus.PrintInside();
    }
    else if (operations == '*')
    {
        if (numCol1 != numRow2)
        {
            cout << "Invalid Matrix Operation" << endl;
            return 0;
        }
        // do the multiplication of both matrices

        cout << "\nmultiplication *\n\n";
        s1.PrintInside();
        cout << "\n*\n\n";
        s2.PrintInside();
        cout << "\n=\n\n";
        SparseMatrix test = s1 * s2;
        
        test.PrintInside();
        cout << "\nright output\n\n";
        Matrix ans = m1 * m2;
        ans.Print();

    }

    // we have to delete all the nodes with the values 0

    cout << "\n--------------------------------\n\n";
    // the end

    SparseMatrix m0(numRow1, numCol1);
    m0.Frame();
    m0.PrintFrame();
    /*SparseMatrix p()
    m0.PrintInside();*/

    return 0;
}

