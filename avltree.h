//lab3 functional

#pragma once
#include "value.h"
#include "node.h"
#include "value.h"
#include "elem.h"
#include "stack.h"

/*
Comments about implementation:
It if possible (more likely) to use OVERLOADING for functions:
private_insert
private_displayTree
private_preOrder
*/

class AvlTree
{
private:
     node *root = NULL;
    // A function to get height of the tree
    int height(struct node *N);
 
    // A function to get maximum of two integers
    int max(int a, int b);
 
    // A function to right rotate subtree rooted with y
    struct node *rightRotate(struct node *y);
 
    // A function to left rotate subtree rooted with x
    struct node *leftRotate(struct node *x);
 
    // Get Balance of node N
    int getBalance(struct node *N);

    struct node* private_insert(struct node* new_node, Value key);
    void private_displayTree(node *ptr, int level);
    void private_preOrder(struct node *root);

public:

    //Enter new element
    void insert(Value key);

    //The function prints preorder of all nodes.
    void preOrder();

    void displayTree(int level);
};
