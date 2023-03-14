#pragma once
#include <iostream>

using namespace std;

class Node
{
protected:
    int row;
    int col;
    int data;

public:
};

class HeaderNode : public Node
{
private:
    Node *right;
    Node *down;

public:
    HeaderNode();
    int getRight();
};

class InternalNode : public Node
{
private:
    Node *left;
    Node *right;
    Node *up;
    Node *down;

public:
};
