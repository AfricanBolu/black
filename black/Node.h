#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node()
    {
        data = 0;
    }
};

class HeaderNode : public Node
{
public:
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
    HeaderNode(int num) : Node()
    {
        num = data;
        right = nullptr;
        down = nullptr;
    }
};

class InternalNode : public Node
{
public:
    // int value;
    int row;
    int col;
    Node *left;
    Node *right;
    Node *up;
    Node *down;

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
};
