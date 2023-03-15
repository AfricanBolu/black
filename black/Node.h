#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
    //virtual ~Node() {}
    int data;
    Node();
    Node(int _data) {
        data = data;
    }
};

class HeaderNode : public Node
{
public:
    Node *right;
    Node *down;
    HeaderNode()
    {
        right = nullptr;
        down = nullptr;
    }
    // void setRightNode(Node* right) {
    // col = right;
    // }
    HeaderNode(int num) : Node(data)
    {
        right = nullptr;
        down = nullptr;
    }
};

class InternalNode : public Node
{
public:
    //int value;
    int row;
    int col;
    Node *left;
    Node *right;
    Node *up;
    Node *down;

    InternalNode(int val, int r, int c)
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
