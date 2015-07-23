#include "stdafx.h"
#include <iostream>
#include<queue>
using namespace std;
typedef struct BinaryTreeNode
{
	int m_value;
	struct BinaryTreeNode *m_left;
	struct BinaryTreeNode *m_right;
	BinaryTreeNode()
	{
		m_value=0;
		m_left=NULL;
		m_right=NULL;
	}
}Node;
Node*  construtBinaryTree(int *start,int *end);

void printBinaryTreeUpToDown(Node *root)
{
	if(root==NULL)return ;
	deque<Node *> nodeDeque;
	nodeDeque.push_back(root);
	/*printf("%d",root->m_value);*/
	while(!nodeDeque.empty())
	{
		Node *node=nodeDeque.front();

		printf("%d  ",node->m_value);

		if(node->m_left!=NULL)
		{
			nodeDeque.push_back(node->m_left);
		}
		if(node->m_right!=NULL)
		{
			nodeDeque.push_back(node->m_right);
			
		}

		nodeDeque.pop_front();
	}
}
//void main()
//{
//		Node *tree1=NULL;
//		int data[]={5,7,6,9,11,10,8};
//		int *pdata=data;
//		tree1=construtBinaryTree(pdata,pdata+6);
//
//
//		printBinaryTreeUpToDown(tree1);
//	
//
//
//}
