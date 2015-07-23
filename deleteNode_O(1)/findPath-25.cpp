#include "stdafx.h"
#include <iostream>
#include <vector>
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

extern Node *construct(int *preorder,int *inorder,int len);

void findPath(Node *headNode,vector<int> data,int value)
{
	if(headNode==NULL)return ;
	//vector<int> storeData;
	Node *pNode=headNode;
	data.push_back(pNode->m_value);
	if(pNode->m_left==NULL&&pNode->m_right==NULL)//叶子节点
	{
		int sum=0;
		for(int i=0;i<data.size();i++)
		{
			sum+=data[i];
		}
		if(sum==value)
		{
			for(int i=0;i<data.size();i++)
			{
				printf("%d ",data[i]);
			}
			printf("\n");
		}

	}
	
	if(headNode->m_left)
	findPath(headNode->m_left,data,value);
	if(headNode->m_right)
	findPath(headNode->m_right,data,value);
	
	data.pop_back();

}










//void main()
//{
//	int preorder[5]={10,5,4,7,12};
//	int inorder[5]={4,5,7,10,12};
//
//	vector<int> datapath;
//	Node *headNode=construct(preorder,inorder,5);
//	// 前序遍历
//	
//	findPath(headNode,datapath,22);
//
//}