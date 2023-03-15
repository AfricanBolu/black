#pragma once
#include <iostream>

using namespace std;

class Node
{
public:
    //virtual ~Node() {}
    int data;
    Node(int _data) {
        data = data;
    }
};

class HeaderNode : public Node
{
public:
    //int data;
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
    /*Node* getRightNode() {
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
