// Calculator class handles the operational guts of our calculator 
// Chris Otto

#include <stdio.h>
#include <iostream>
#include <ctype.h>

#ifndef CALCULATOR_H
#define CALCULATOR_H

#define OPERATOR 0
#define DATA 1
#define FAIL 1
#define SUCCEED 0

using namespace std;

typedef
struct {
	int data;
	int dataType;
} DataNode;

typedef
struct node {
	DataNode *nodeData;
	struct node *leftChild;
	struct node *rightChild;
} TreeNode;

ref class calculator
{
public:
	calculator(void);
	~calculator(void);
	void mainMethod();
private:
	int scan(DataNode *data, FILE *fptr);
	TreeNode *make_TreeNode(DataNode *data);
	void insertTreeNode(TreeNode *newTreeNode, TreeNode **root);
	void inOrder(TreeNode *currentTreeNode);
	void preOrder(TreeNode *currentTreeNode);
	void postOrder(TreeNode *currentTreeNode);
};

#endif