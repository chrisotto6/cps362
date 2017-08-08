// Chris Otto - calculator implementation

#include "calculator.h"

calculator::calculator(void)
{
}


calculator::~calculator(void)
{
}

void calculator::insertTreeNode(TreeNode *newTreeNode, TreeNode **root)
{
	if (*root == (TreeNode*)NULL)
	{
		*root = newTreeNode;
	}
	else
	{
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
TreeNode* calculator::make_TreeNode(DataNode *data)
{
	TreeNode *newptr = NULL;
	if ((newptr = (TreeNode *)malloc(sizeof(TreeNode))) != (TreeNode *)NULL)
	{
		newptr->nodeData = data;
		newptr->leftChild = (TreeNode *)NULL;
		newptr->rightChild = (TreeNode *)NULL;
	}
	
	return (newptr);
}


void calculator::mainMethod()
{
	DataNode *node = NULL;
	TreeNode *newTreeNode = NULL;
	TreeNode *root = NULL;

	int resultCode;

	cout << "\nEnter an Expression (ex.3+2/1*4)" << endl;

	node = (DataNode*)malloc(sizeof(DataNode));

	while ((resultCode = scan(node, stdin)) != EOF)
	{
		newTreeNode = make_TreeNode(node);
		insertTreeNode(newTreeNode, &root);

		node = (DataNode*)malloc(sizeof(DataNode));
	}

	cout << "\nIn Order Traversal " << endl;
	inOrder(root);
	cout << endl;

	cout << "\nPre Order Traversal " << endl;
	preOrder(root);
	cout << endl;

	cout << "\nPost Order Traversal " << endl;
	postOrder(root);
	cout << endl;
}

int calculator::scan(DataNode *node, FILE *fptr)
{
	char c = 0;
	int resultCode = SUCCEED;
	while (isspace(c = (char)fgetc(fptr)) && (c != '\n')); 

	switch (c) {
	case '+': case '-':
	case '*': case '/':
		(*node).dataType = OPERATOR;
		(*node).data = c;
		break;

	case '0': case '1':
	case '2': case '3':
	case '4': case '5':
	case '6': case '7':
	case '8': case '9':
		(*node).dataType = DATA;
		(*node).data = c - '0';
		break;

	case '\n':
	case EOF:
		(*node).data = 0;
		resultCode = EOF;
		break;
	default:
		(*node).data = c;
		resultCode = FAIL;
		break;
	}
	return resultCode;
}

void calculator::inOrder(TreeNode *currentTreeNode)
{
	int nodeValue = 0;
	int leftValue = 0;
	int rightValue = 0;

	if (currentTreeNode != NULL)
	{
		inOrder(currentTreeNode->leftChild);

		if (currentTreeNode->nodeData->dataType == OPERATOR) //parent 
			cout << (char)currentTreeNode->nodeData->data;
		else
			cout << currentTreeNode->nodeData->data;

		inOrder(currentTreeNode->rightChild);
	}
}

void calculator::preOrder(TreeNode *currentTreeNode)
{
	int nodeValue = 0;
	int leftValue = 0;
	int rightValue = 0;

	if (currentTreeNode != NULL)
	{
		if (currentTreeNode->nodeData->dataType == OPERATOR)
			cout << (char)currentTreeNode->nodeData->data;
		else
			cout << currentTreeNode->nodeData->data;

		preOrder(currentTreeNode->leftChild);
		preOrder(currentTreeNode->rightChild);
	}
}

void calculator::postOrder(TreeNode * currentTreeNode)
{
	int nodeValue = 0;
	int leftValue = 0;
	int rightValue = 0;

	if (currentTreeNode != NULL)
	{
		postOrder(currentTreeNode->leftChild);
		postOrder(currentTreeNode->rightChild);

		if (currentTreeNode->nodeData->dataType == OPERATOR)
			cout << (char)currentTreeNode->nodeData->data;
		else
			cout << currentTreeNode->nodeData->data;
	}
}

