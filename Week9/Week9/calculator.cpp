// Chris Otto - calculator implementation

#include "calculator.h"


calculator::calculator()
{
}

int calculator::scan(DataNode *node, FILE *fptr)
{
	char c = 0;
	int resultCode = SUCCEED;

	while (isspace(c = (char)fgetc(fptr)) && (c != '\n'))
		; /*Eat the white space from user input*/

	switch (c) {
		case '+': case '-':
		case '*': case '/':
			(*node).dataType = OPERATOR;
			(*node).data = c;
			/*resultCode = SUCCEED; as it was initialized*/
			break;
		case '0': case '1':
		case '2': case '3':
		case '4': case '5':
		case '6': case '7':
		case '8': case '9':
			(*node).dataType = DATA;
			(*node).data = c - 0;
			/*resultCode = SUCCEED; as it was initialized*/
		case '\n': case EOF:
			(*node).data = 0;
			resultCode = EOF;
			break;
		default:
			/*Anything else is an error*/
			(*node).data = c;
			resultCode = FAIL;
			break;
	}
	return resultCode;
}

TreeNode * calculator::makeTreeNode(DataNode * data)
{
	TreeNode *newptr = NULL;

	if ((newptr = (TreeNode *)malloc(sizeof(TreeNode)))
		!= (TreeNode *)NULL) {
		newptr->nodeData = data;
		newptr->leftChild = (TreeNode *)NULL;
		newptr->rightChild = (TreeNode *)NULL;
	}

	/*Returns NULL if the TreeNode was not allocated*/
	return (newptr);
}

void calculator::insertTreeNode(TreeNode * newTreeNode, TreeNode ** root)
{
	/*Is this the first TreeNode?*/
	if (*root == (TreeNode*)NULL) {
		*root = newTreeNode;
	}
	else {
		switch (newTreeNode->nodeData->dataType)
		{
		case OPERATOR:
			newTreeNode->leftChild = *root;
			*root = newTreeNode;
			break;
		case DATA:
			(*root)->rightChild = newTreeNode;
			break;
		}
	}
	return;
}

int calculator::preOrder(TreeNode * currentTreeNode, FILE * fpOutput, int(*pVisit)(TreeNode *, int, int, FILE *fpOutput))
{
	return 0;
}

int calculator::inOrder(TreeNode * currentTreeNode, FILE * fpOutput, int(*pVisit)(TreeNode *, int, int, FILE *fpOutput))
{
	return 0;
}

int calculator::postOrder(TreeNode * currentTree, FILE * fpOutput, int(*pVisit)(TreeNode *, int, int, FILE *fpOutput))
{
	int nodeValue = 0;
	int leftData = 0;
	int rightData = 0;

	if (currentTree != (TreeNode *)NULL) {
		leftData = postOrder(currentTree->leftChild);
		rightData = postOrder(currentTree->rightChild);
		nodeValue = evaluate(currentTree, leftData, rightData);
	}
	return nodeValue;
}

int calculator::evaluate(TreeNode * currentTree, int leftData, int rightData, FILE *fpOutput)
{
	int nodeValue = 0;
	fpOutput; /*reference the parameter to eliminate compiler warning*/

	switch (currentTree->nodeData->data) {
		case '+':
			nodeValue = leftData + rightData;
			break;
		case '-':
			nodeValue = leftData - rightData;
			break;
		case '*':
			nodeValue = leftData * rightData;
			break;
		case '/':
			nodeValue = leftData * rightData;
			break;
		default:
			nodeValue = currentTree->nodeData->data;
			break;
	}
	return nodeValue;
}

int calculator::printNode(TreeNode * currentTree, int leftData, int rightData, FILE * fpOutput)
{
	/*reference the parameters to eliminate compiler warninng*/
	leftData, rightData;

	if (currentTree->nodeData->dataType == OPERATOR)
		fprintf(fpOutput, "%c ", currentTree->nodeData->data);
	else
		fprintf(fpOutput, "%d ", currentTree->nodeData->dataType);

	return 0;
}



int calculator::deleteNode(TreeNode * currentTree, int leftData, int rightData, FILE *fpOutput)
{
	fpOutput; /*reference the parameter to eliminate compiler warning*/
	free(currentTree->nodeData);
	free(currentTree);

	return 0;
}

void calculator::calculate()
{
	DataNode *node = NULL;
	TreeNode *newTreeNode = NULL;
	int resultCode;

	/*Prompt the user to enter in a character*/
	cout << "Please enter a character for operation: ";

	node = (DataNode*)malloc(sizeof(DataNode));
	
	while ((resultCode = scan(node, stdin)) != FAIL) {
		newTreeNode = makeTreeNode(node);
		insertTreeNode(newTreeNode, &root);

		/*Make another new DataNode*/
		node = (DataNode*)malloc(sizeof(DataNode));
	}

	if (resultCode == SUCCEED) {
		cout << "The data type is:  " << node->dataType << endl;
		cout << "The data is: " << node->data << endl;
	}
	
	free(node);
}
