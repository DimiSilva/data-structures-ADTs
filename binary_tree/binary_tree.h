#ifndef BINARY_TREE_H_INCLUDED
#define BINARY_TREE_H_INCLUDED

typedef struct NODE* BinaryTree;
BinaryTree* createBinaryTree();
void cutDownBinaryTree(BinaryTree* root);

int isEmptyBinaryTree(BinaryTree* root);
int getHeightOfBinaryTree(BinaryTree* root);
int countNodesOfBinaryTree(BinaryTree* root);

void printPreOrderBinaryTree(BinaryTree* root);
void printInOrderBinaryTree(BinaryTree* root);
void printPostOrderBinaryTree(BinaryTree* root);

int insertInBinaryTree(BinaryTree* root, int value);

int removeFromBinaryTree(BinaryTree* root, int value);

int includesInBinaryTree(BinaryTree* root, int value);

#endif
