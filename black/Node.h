#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
    virtual ~Node() {}
};

class HeaderNode : public Node
{
public:
    int data;
    Node *right;
    Node *down;

public:
    HeaderNode()
    {
        right = nullptr;
        down = nullptr;
    }
    // void setRightNode(Node* right) {
    // col = right;
    // }
    Node *getRightNode()
    {
        return right;
    }
    HeaderNode(int num)
    {
        data = num;
        right = nullptr;
        down = nullptr;
    }
    // int getRight();
};

class InternalNode : public Node
{
public:
    int value;
    int row;
    int col;
    Node *left;
    Node *right;
    Node *up;
    Node *down;

    InternalNode(int val, int r, int c)
    {
        value = val;
        row = r;
        col = c;
        left = nullptr;
        right = nullptr;
        up = nullptr;
        down = nullptr;
    }
};
