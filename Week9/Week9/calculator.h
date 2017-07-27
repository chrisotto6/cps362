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
	calculator();
	void calculate();
	int scan(DataNode *node, FILE *fptr); /*Gets the input*/
	TreeNode *makeTreeNode(DataNode *data);
	void insertTreeNode(TreeNode *newTreeNode, TreeNode **root);
	int preOrder(TreeNode *currentTreeNode, FILE *fpOutput,
		int(*pVisit)(TreeNode *, int, int, FILE *fpOutput));
	int inOrder(TreeNode *currentTreeNode, FILE *fpOutput,
		int(*pVisit)(TreeNode *, int, int, FILE *fpOutput));
	/*deleteTree*/
	int postOrder(TreeNode *currentTree, FILE *fpOutput,
		int(*pVisit)(TreeNode *, int, int, FILE *fpOutput));
	int evaluate(TreeNode *currentTree, int leftData, int rightData, FILE *fpOutput);
	int printNode(TreeNode *currentTree, int leftData, int rightData, FILE *fpOutput);
	int deleteNode(TreeNode *currentTree, int leftData, int rightData, FILE *fpOutput);

};

#endif