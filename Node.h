#include <iostream>
#include "NodeInterface.h"

class Node: public NodeInterface {

public:
    Node() {
        value = -99999;
        left = right = NULL;
    }
    Node(int data){
        value = data;
        left = right = NULL;
    }
    ~Node() {}

    /*
    * Returns the data that is stored in this node
    *
    * @return the data that is stored in this node.
    */
    int getData() const {
        return value;
    }

    /*
    * Returns the left child of this node or null if it doesn't have one.
    *
    * @return the left child of this node or null if it doesn't have one.
    */
    Node *getLeftChild() const {
        return left;
    }

    /*
    * Returns the right child of this node or null if it doesn't have one.
    *
    * @return the right child of this node or null if it doesn't have one.
    */
    Node *getRightChild() const {
        return right;
    }

    friend class BST;
private:
    int value;
    Node *right;
    Node *left;
};