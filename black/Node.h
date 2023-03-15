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

<<<<<<< HEAD
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
=======
    HeaderNode(int num)
    {
        value = num;
        right = nullptr;
        down = nullptr;
    }
    // int getRight();
>>>>>>> a1bbcc63f09ce5f9968e1c582925abbf59f10697
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
