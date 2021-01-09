#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

void nodePruneForCutDown(struct NODE* node);
struct NODE* nodePrune(struct NODE* node);

struct NODE
{
    int value;
    struct NODE* left;
    struct NODE* right;
};

BinaryTree* createBinaryTree()
{
    BinaryTree* root = (BinaryTree*) malloc(sizeof(BinaryTree));
    if(root != NULL) *root = NULL;
    return root;
}

void cutDownBinaryTree(BinaryTree* root)
{
    if(root == NULL) return;
    nodePruneForCutDown(*root);
    free(root);
}

void nodePruneForCutDown(struct NODE* node)
{
    if(node == NULL) return;
    nodePruneForCutDown(node->left);
    nodePruneForCutDown(node->right);
    free(node);
    node = NULL;
}

int isEmptyBinaryTree(BinaryTree* root)
{
    return root == NULL || *root == NULL ? 1 : 0;
}

int getHeightOfBinaryTree(BinaryTree* root)
{
    if(root == NULL || *root == NULL) return 0;

    int leftHeight = getHeightOfBinaryTree(&((*root)->left));
    int rightHeight = getHeightOfBinaryTree(&((*root)->right));

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int countNodesOfBinaryTree(BinaryTree* root)
{
    if(root == NULL || *root == NULL) return 0;

    int leftHeight = getHeightOfBinaryTree(&((*root)->left));
    int rightHeight = getHeightOfBinaryTree(&((*root)->right));

    return leftHeight + rightHeight + 1;
}

void printPreOrderBinaryTree(BinaryTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printf("%d\n", (*root)->value);
        printPreOrderBinaryTree(&((*root)->left));
        printPreOrderBinaryTree(&((*root)->right));
    }
}

void printInOrderBinaryTree(BinaryTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printInOrderBinaryTree(&((*root)->left));
        printf("%d\n", (*root)->value);
        printInOrderBinaryTree(&((*root)->right));
    }
}

void printPostOrderBinaryTree(BinaryTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printPostOrderBinaryTree(&((*root)->left));
        printPostOrderBinaryTree(&((*root)->right));
        printf("%d\n", (*root)->value);
    }
}

int insertInBinaryTree(BinaryTree* root, int value)
{
    if(root == NULL) return 0;

    struct NODE* newNode;
    newNode = (struct NODE*) malloc(sizeof(struct NODE));

    if(newNode == NULL) return 0;

    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;

    if(*root == NULL) *root = newNode;
    else
    {
        struct NODE* current = *root;
        struct NODE* previous = NULL;

        while(current != NULL)
        {
            previous = current;
            if(value == current->value)
            {
                free(newNode);
                return 0;
            }
            if(value > current->value) current = current->right;
            else current = current->left;
        }

        if(value > previous->value) previous->right = newNode;
        else previous->left = newNode;
    }

    return 1;
}

int removeFromBinaryTree(BinaryTree* root, int value)
{
    if(root == NULL) return 0;

    struct NODE* current = *root;
    struct NODE* previous = NULL;
    while(current != NULL)
    {
        if(value == current->value)
        {
            if(current == *root) *root = nodePrune(current);
            else
            {
                if(previous->right == current)previous->right = nodePrune(current);
                else previous->left = nodePrune(current);
            }
            return 1;
        }
        previous = current;
        if(value > current->value) current = current->right;
        else current = current->left;
    }
}

struct NODE* nodePrune(struct NODE* node)
{
    struct NODE *node1, *node2;

    if(node->left == NULL)
    {
        node2 = node->right;
        free(node);
        return node2;
    }

    node1 = node;
    node2 = node->left;

    while(node2->right != NULL)
    {
        node1 = node2;
        node2 = node2->right;
    }

    if(node1 != node)
    {
        node1->right = node2->left;
        node2->left = node->left;
    }

    node2->right = node->right;
    free(node);
    return node2;
}

int includesInBinaryTree(BinaryTree* root, int value)
{
    if(root == NULL) return 0;

    struct NODE* current = *root;
    while(current != NULL) {
        if(value == current->value) return 1;
        if(value > current->value) current = current->right;
        else current = current->left;
    }
}
