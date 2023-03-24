#pragma once
#include <iostream>

using namespace std;

class HeaderNode
{
public:
    int data;
    HeaderNode *right;
    HeaderNode *down;
    HeaderNode()
    {
        right = nullptr;
        down = nullptr;
    }
    // void setRightNode(Node* right) {
    // col = right;
    // }
    HeaderNode(int num)
    {
        num = data;
        right = nullptr;
        down = nullptr;
    }
};

class InternalNode : public HeaderNode
{
public:
    // int value;
    int row;
    int col;
    InternalNode *left;
    InternalNode *right;
    InternalNode *up;
    InternalNode *down;

    InternalNode(int r, int c, int val)
    {
        data = val;
        row = r;
        col = c;
        left = nullptr;
        right = nullptr;
        up = nullptr;
        down = nullptr;
    }

    void PrintInfo()
    {
        cout << "node address: " << this << endl;
        cout << "row: " << row << " col: " << col << " data: " << data << endl;
        cout << "left: " << left << endl;
        cout << "right: " << right << endl;
        cout << "up: " << up << endl;
        cout << "down: " << down << endl;
    }
};
