//lab3 functional

#include <iostream>
#include <cstdlib>
#include "avltree.h"
using namespace std;

 
// A function to get height of the tree
int AvlTree::height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
 
// A function to get maximum of two integers
int AvlTree::max(int a, int b)
{
    return (a > b)? a : b;
}
 
// A function to right rotate subtree rooted with y
struct node * AvlTree::rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A function to left rotate subtree rooted with x
struct node * AvlTree::leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //Updating heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
 
// Get Balance factor of node N
int AvlTree::getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

void AvlTree::insert(Value key) // rename!!!
{
    root = private_insert(root, key);

}

struct node* AvlTree::private_insert(struct node* new_node, Value key) // rename!!!
{
    //1.  Perform the normal BST rotation
    if (new_node == NULL)
    {
        return new struct node(key);
    }
 
    if (key.getValue() < new_node->key.getValue())
        new_node->left  = private_insert(new_node->left, key);
    else if (key.getValue() > new_node->key.getValue())
        new_node->right = private_insert(new_node->right, key);
    //можно сделать через функцию compare (==)
    else if (key.getValue() == new_node->key.getValue()) //if tqual element is in tree -> not to write it
    {
        return new_node;
    }
 
    //2. Update height of this ancestor node
    new_node->height = max(height(new_node->left), height(new_node->right)) + 1;
 
    //3. Get the balance factor of this ancestor(предок) node to check whether this node became unbalanced
    int balance = getBalance(new_node);
 
    // If this node becomes unbalanced than do:
    // Left Left Case
    if (balance > 1 && key.getValue() <= new_node->left->key.getValue())
        return rightRotate(new_node);
 
    // Right Right Case
    if (balance < -1 && key.getValue() >= new_node->right->key.getValue())
        return leftRotate(new_node);
 
    // Left Right Case
    if (balance > 1 && key.getValue() >= new_node->left->key.getValue())
    {
        new_node->left =  leftRotate(new_node->left);
        return rightRotate(new_node);
    }
 
    // Right Left Case
    if (balance < -1 && key.getValue() <= new_node->right->key.getValue())
    {
        new_node->right = rightRotate(new_node->right);
        return leftRotate(new_node);
    }
 
    //return the (unchanged) node pointer
    return new_node;
}

//The function prints preorder all nodes.
void AvlTree::preOrder()
{
    private_preOrder(root);
}
  
void AvlTree::private_preOrder(struct node *root)
{
    if(root != NULL)
    {
        cout << root->key.getValue() << " ";
        private_preOrder(root->left);
        private_preOrder(root->right);
    }
}

//Display Tree
//void AvlTree::displayTree(node *ptr, int level)
void AvlTree::displayTree(int level)
{
    private_displayTree(root, level);
}

void AvlTree::private_displayTree(node *ptr, int level)
{
	node * root_tmp;
    int i;
    if (ptr!=NULL)
    {
        private_displayTree(ptr->right, level + 1);
        cout << endl;
        if (ptr == root_tmp)
            cout<<"Root -> ";
        for (i = 0; i < level && ptr != root_tmp; i++)
            cout<<"        ";
        cout<<ptr->key.getValue();
        private_displayTree(ptr->left, level + 1);
    }
}