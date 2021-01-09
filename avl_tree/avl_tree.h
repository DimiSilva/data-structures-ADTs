#ifndef AVL_TREE_H_INCLUDED
#define AVL_TREE_H_INCLUDED

typedef struct NODE* AVLTree;
AVLTree* createAVLTree();
void cutDownAVLTree(AVLTree* root);

int isEmptyAVLTree(AVLTree* root);
int getHeightOfAVLTree(AVLTree* root);
int countNodesOfAVLTree(AVLTree* root);

void printPreOrderAVLTree(AVLTree* root);
void printInOrderAVLTree(AVLTree* root);
void printPostOrderAVLTree(AVLTree* root);

int insertInAVLTree(AVLTree* root, int value);

int removeFromAVLTree(AVLTree* root, int value);

int includesInAVLTree(AVLTree* root, int value);

#endif
