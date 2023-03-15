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
    HeaderNode() {
        right = NULL;
        down = NULL;
    }
    //void setRightNode(Node* right) {
    //    //col = right;
    //}
    Node* getRightNode() {
        return right;
    }
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
