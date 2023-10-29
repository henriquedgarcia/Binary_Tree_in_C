#include "bintree.h"
#include <stdlib.h>

struct BinNode {
	void *value;
	BinNode *left;
	BinNode *right;
	BinNode *parent;
};

void* info(BinNode *node) {
	return node->value;
}

BinNode* left(BinNode *node) {
	return node->left;
}

BinNode* right(BinNode *node) {
	return node->right;
}

BinNode* parent(BinNode *node) {
	return node->parent;
}

BinNode* brother(BinNode *node){
	if(parent(node)==NULL)
		return NULL;
	if(isLeft(node))
		return right(parent(node));
    return left(parent(node));
}

BinNode* min(BinNode *node){
    if(isLeaf(node)) return node;
    min(left(node));
}

BinNode* max(BinNode *node){
    if(isLeaf(node)) return node;
    min(right(node));
}

BinNode* successor(BinNode *node){
    if (node == NULL) 
        return NULL;

    if (right(node)!=NULL) 
        return min(node);
    while(parent(node)!=NULL && isRight(node)) 
        node = parent(node);
    
    return parent(node);
}

BinNode* predecessor(BinNode *node){
    if (node == NULL) 
        return NULL;

    if (left(node)!=NULL) 
        return max(node);
    while(parent(node)!=NULL && isLeft(node)) 
        node = parent(node);
    
    return parent(node);
}

bool isLeft(BinNode *node) {
	if (node == left(parent(node))) 
		return true;
    return false;
}

bool isRight(BinNode *node) {
	if (node == right(parent(node)))
		return true;
    return false;
}

bool isLeaf(BinNode *node){
	if (left(node)==NULL && right(node)==NULL)
		return true;
    return false;
}

bool isRoot(BinNode *node) {
	if (parent(node) == NULL)
		return true;
    return false;
}

BinNode* makeNode(void *value) {
	BinNode *node = (BinNode*) malloc(sizeof(BinNode));
	node->value = value;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BinNode* setLeft(BinNode *node, void *value) {	
	BinNode *newNode = makeNode(value);
	node->left = newNode;
	setParent(node, newNode);
	return newNode;
}

BinNode* setRight(BinNode *node, void *value) {
	BinNode *newNode = makeNode(value);
    node->right = newNode;
    setParent(node, newNode);
	return newNode;
}

BinNode* bstInsert(BinNode* node, void *value) {
    if (value < info(node)) {
        if (left(node) == NULL)
            setLeft(node, value);
        else
            insertBST(left(node), value);
    }
    else {
        if (right(node) == NULL)
            setRight(node, value);
        else
            insertBST(right(node), value);
    }
    return node;
}

void setParent(BinNode *parent, BinNode *child){
    child->parent = parent;
}

void remove(BinNode *node);
void prune(BinNode *node);

BinNode* search(BinNode* node, void *value) {
    if (node == NULL || info(node) == value)
        return node;
    
    if (value < info(node))
        return searchBST(left(node), value);
    else
        return searchBST(right(node), value);
}

void printTree(BinNode* node) {
    static int level = 0;
    if (node == NULL)
        return;
        
    level++;
    printTree(right(node));
    for (int i = 0; i < level-1; i++) printf("    ");
    printf("+----%d\n", (int*)info(node));
    printTree(left(node));
    level--;
}

void showNode(BinNode *node) {
    printf("Value: %d\n", (int*)info(node));
	if (parent(node) != NULL) 
        printf("Parent: %d\n", (int*)info(parent(node)));
    else 
        printf("Parent: NULL\n");
    
	if(left(node)!=NULL) 
		printf("Left: %d\n", (int*)info(left(node)));
	else
		printf("Left: NULL\n");
	
	if(right(node)!=NULL) 
		printf("Right: %d\n", (int*)info(right(node)));
	else
		printf("Right: NULL\n");
    printf("\n\n");
}
