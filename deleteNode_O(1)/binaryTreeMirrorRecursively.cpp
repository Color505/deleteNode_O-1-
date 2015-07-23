#include "stdafx.h"
#include <iostream>
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

extern Node*  construtBinaryTree(int *start,int *end);
extern bool preorderTraversal(Node *head);
extern bool aftorderTraversal(Node *head);
 Node *binaryTreeMirrorRecursively(Node *root)
 {
	 if(root==NULL)return NULL;

	 Node *curNode=root;

	 if(root->m_left!=NULL ||root->m_right!=NULL)
	 {
		 Node *temp=curNode->m_left;
		 curNode->m_left=curNode->m_right;
		 curNode->m_right=temp;
		 binaryTreeMirrorRecursively(curNode->m_left);
		 binaryTreeMirrorRecursively(curNode->m_right);
	 }
	 else
	 {
		 return NULL;
	 }

	 return curNode;
 }

 
//void main()
//{
//		Node *tree1=NULL;
//		int data[]={10,9,7,5/*,6,9,11,10,8*/};
//		int *pdata=data;
//		tree1=construtBinaryTree(pdata,pdata+3);
//		aftorderTraversal(tree1);
//		Node *mirrorTree=binaryTreeMirrorRecursively(tree1);
//		aftorderTraversal(mirrorTree);
//
//}