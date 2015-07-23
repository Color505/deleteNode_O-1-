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

Node* creatBinaryTree(int *startPreorder,int *endPreorder,int *startInorder,int *endInorder)
{
	if(startPreorder==NULL ||endPreorder==NULL ||startInorder==NULL || endInorder==NULL)return NULL;

	Node *node=new Node();
	node->m_value=startPreorder[0];
	node->m_left=NULL;
	node->m_right=NULL;

	int i=0;

	if(startPreorder==endPreorder)
	{
		if(startInorder==endInorder && *startPreorder==*startInorder)
		{
			return node;//���ظ��ڵ�
		}

	}

	for( ;i<endInorder-startInorder+1 ;i++)
	{
		if(startInorder[i]==startPreorder[0])
		{
			break;
		}
	}

	if(i>=endInorder-startInorder+1) return NULL;

	int leftLen=i;
	int *leftPreorderEnd=startPreorder+i;
	if(leftLen>0)
	{
		node->m_left=creatBinaryTree(startPreorder+1,leftPreorderEnd,startInorder,startInorder+i-1);
	}
	if(leftLen<endPreorder-startPreorder)
	{
		node->m_right=creatBinaryTree(leftPreorderEnd+1,endPreorder,startInorder+i+1,endInorder);
	}
	return node;
}
//�����������4,7,2,1,5,3,8,6��ǰ�����1,2,4,7,3,5,6,8,����һ������������ δ���� �������
Node*  construct(int *preorder,int *inorder,int len)
{
	if(preorder==NULL || inorder==NULL ||len==0)return NULL;

	return creatBinaryTree(preorder,preorder+len-1,inorder,inorder+len-1);
	
}

//ǰ�����
bool preorderTraversal(Node *head)
{
	if(head==NULL) return false;
	printf("%d ",head->m_value);
	preorderTraversal(head->m_left);
	preorderTraversal(head->m_right);
	return true;
}

//�������
bool inorderTraversal(Node *head)
{
	if(head==NULL) return false;
	inorderTraversal(head->m_left);
	printf("%d ",head->m_value);
	inorderTraversal(head->m_right);
	return true;
	
}

//�������
bool aftorderTraversal(Node *head)
{
	if(head==NULL) return false;
	aftorderTraversal(head->m_left);
	aftorderTraversal(head->m_right);
	printf("%d ",head->m_value);
	return true;
}

//
//void main()
//{
//	int preorder[8]={1,2,6,8,4,3,5};
//	int inorder[8]={6,2,8,1,3,4,5};
//
//	Node *headNode=construct(preorder,inorder,7);
//	// ǰ�����
//	preorderTraversal(headNode);
//	//�������
//	inorderTraversal(headNode);
//	//�������
//	aftorderTraversal(headNode);
//	cout<<preorder[3]<<endl;
//
//}