// bintree.h
#ifndef BINTREE_H
#define BINTREE_H

#include <stdbool.h>

typedef struct BinNode BinNode;

void* info(BinNode *node);
BinNode* left(BinNode *node);
BinNode* right(BinNode *node);
BinNode* parent(BinNode *node);
BinNode* brother(BinNode *node);
BinNode* min(BinNode *node);
BinNode* max(BinNode *node);
BinNode* successor(BinNode *node);
BinNode* predecessor(BinNode *node);

bool isLeft(BinNode *node);
bool isRight(BinNode *node);
bool isLeaf(BinNode *node);
bool isRoot(BinNode *node);

BinNode* makeNode(void *value);
BinNode* setLeft(BinNode *node, void *value);
BinNode* setRight(BinNode *node, void *value);
BinNode* bstInsert(BinNode* node, void *value);

void bind(BinNode *parent, BinNode *child);
void remove(BinNode *node);
void prune(BinNode *node);

BinNode* search(BinNode* node, void *value);

void printTree(BinNode* root);
void showNode(BinNode* node);

#endif
