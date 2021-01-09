#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"

void nodePruneForCutDown(struct NODE* node);

int getNodeHeight(struct NODE* node);
int calculateNodeBalance(struct NODE* node);
int biggest(int x, int y);
struct NODE* findSmallestNode(struct NODE* node);

void nodeLLRotate(AVLTree* root);
void nodeRRRotate(AVLTree* root);
void nodeLRRotate(AVLTree* root);
void nodeRLRotate(AVLTree* root);

struct NODE
{
    int value;
    int height;
    int balance;
    struct NODE* left;
    struct NODE* right;
};

AVLTree* createAVLTree()
{
    AVLTree* root = (AVLTree*) malloc(sizeof(AVLTree));
    if(root != NULL) *root = NULL;
    return root;
}

void cutDownAVLTree(AVLTree* root)
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

int isEmptyAVLTree(AVLTree* root)
{
    return root == NULL || *root == NULL ? 1 : 0;
}

int getHeightOfAVLTree(AVLTree* root)
{
    if(root == NULL || *root == NULL) return 0;

    int leftHeight = getHeightOfAVLTree(&((*root)->left));
    int rightHeight = getHeightOfAVLTree(&((*root)->right));

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

int countNodesOfAVLTree(AVLTree* root)
{
    if(root == NULL || *root == NULL) return 0;

    int leftHeight = getHeightOfAVLTree(&((*root)->left));
    int rightHeight = getHeightOfAVLTree(&((*root)->right));

    return leftHeight + rightHeight + 1;
}

void printPreOrderAVLTree(AVLTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printf("%d\n", (*root)->value);
        printPreOrderAVLTree(&((*root)->left));
        printPreOrderAVLTree(&((*root)->right));
    }
}

void printInOrderAVLTree(AVLTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printInOrderAVLTree(&((*root)->left));
        printf("%d\n", (*root)->value);
        printInOrderAVLTree(&((*root)->right));
    }
}

void printPostOrderAVLTree(AVLTree* root)
{
    if(root == NULL) return;
    if(*root != NULL)
    {
        printPostOrderAVLTree(&((*root)->left));
        printPostOrderAVLTree(&((*root)->right));
        printf("%d\n", (*root)->value);
    }
}

int insertInAVLTree(AVLTree* root, int value)
{
    int result;
    if(*root == NULL)
    {
        struct NODE* newNode;
        newNode = (struct NODE*) malloc(sizeof(struct NODE));
        if(newNode == NULL) return 0;

        newNode->value = value;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode;
        return 1;
    }

    struct NODE* current = *root;
    if(value < current->value)
    {
        if((result=insertInAVLTree(&(current->left), value)) == 1)
        {
            if(calculateNodeBalance(current) >= 2)
            {
                if(value < (*root)->left->value) nodeLLRotate(root);
                else nodeLRRotate(root);
            }
        }
    }
    else if(value > current->value)
    {
        if((result=insertInAVLTree(&(current->right), value)) == 1)
        {
            if(calculateNodeBalance(current) >= 2)
            {
                if(value > (*root)->right->value) nodeRRRotate(root);
                else nodeRLRotate(root);
            }
        }
    }
    else
    {
        return 0;
    }
    current->height = biggest(getNodeHeight(current->left), getNodeHeight(current->right)) + 1;

    return result;
}

int removeFromAVLTree(AVLTree* root, int value)
{
    if(*root == NULL) return 0;

    int result;

    if(value < (*root)->value)
    {
        if((result=removeFromAVLTree(&(*root)->left, value)) == 1)
        {
            if(calculateNodeBalance(*root) >= 2)
            {
                if(getNodeHeight((*root)->right->left) <= getNodeHeight((*root)->right->right)) nodeRRRotate(root);
                else nodeRLRotate(root);
            }
        }
    }
    if(value > (*root)->value)
    {
        if((result=removeFromAVLTree(&(*root)->right, value)) == 1)
        {
            if(calculateNodeBalance(*root) >= 2)
            {
                if(getNodeHeight((*root)->left->right) <= getNodeHeight((*root)->left->left)) nodeLLRotate(root);
                else nodeLRRotate(root);
            }
        }
    }
    if(value == (*root)->value)
    {
        if(((*root)->left== NULL || (*root)->right == NULL))
        {
            struct NODE* oldNode = (*root);
            if((*root)->left != NULL) *root = (*root)->left;
            else *root = (*root)->right;
            free(oldNode);

        }
        else
        {
            struct NODE* temp = findSmallestNode((*root)->right);
            (*root)->value = temp->value;
            removeFromAVLTree(&(*root)->right, (*root)->value);
            if(calculateNodeBalance(*root) >= 2)
            {
                if(getNodeHeight((*root)->left->right) <= getNodeHeight((*root)->left->left)) nodeLLRotate(root);
                else nodeLRRotate(root);
            }
        }
        return 1;
    }

    (*root)->height = biggest(getNodeHeight((*root)->left), getNodeHeight((*root)->right)) + 1;
    return result;
}

int includesInAVLTree(AVLTree* root, int value)
{
    if(root == NULL) return 0;

    struct NODE* current = *root;
    while(current != NULL)
    {
        if(value == current->value) return 1;
        if(value > current->value) current = current->right;
        else current = current->left;
    }
}

int getNodeHeight(struct NODE* node)
{
    if(node == NULL) return -1;
    else return node->height;
}
int calculateNodeBalance(struct NODE* node)
{
    node->balance = labs(getNodeHeight(node->left) - getNodeHeight(node->right));
    return node->balance;
}

int biggest(int x, int y)
{
    return x > y ? x : y;
}

void nodeLLRotate(AVLTree* root)
{
    struct NODE* node;

    node  = (*root)->left;
    (*root)->left = node->right;
    node->right = *root;

    (*root)->height = biggest(getNodeHeight((*root)->left), getNodeHeight((*root)->right)) + 1;

    node->height = biggest(getNodeHeight(node->left), (*root) ->height) + 1;

    *root = node;
}

void nodeRRRotate(AVLTree* root)
{
    struct NODE* node;

    node  = (*root)->right;
    (*root)->right = node->left;
    node->left = *root;

    (*root)->height = biggest(getNodeHeight((*root)->left), getNodeHeight((*root)->right)) + 1;

    node->height = biggest(getNodeHeight(node->right), (*root) ->height) + 1;

    *root = node;
}

void nodeLRRotate(AVLTree* root)
{
    nodeRRRotate(&(*root)->left);
    nodeLLRotate(root);
}

void nodeRLRotate(AVLTree* root)
{
    nodeLLRotate(&(*root)->right);
    nodeRRRotate(root);
}

struct NODE* findSmallestNode(struct NODE* node)
{
    struct NODE* node1 = node;
    struct NODE* node2 = node->left;

    while(node2 != NULL)
    {
        node1 = node2;
        node2 = node2->left;
    }
    return node1;
}
