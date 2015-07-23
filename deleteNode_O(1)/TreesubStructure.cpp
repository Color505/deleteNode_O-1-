#include "stdafx.h"
#include <iostream>
using namespace std;

/*
	题目：输入两课二叉树A和B判断B是不是A的子结构
*/
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

//根据后序遍历,构建一个二叉搜索树 5 7 6 9 11 10 8 未测试 明天测试
Node*  construtBinaryTree(int *start,int *end)
{
	int len=end-start;
	int bData=start[len];
	Node *bNode=new Node();
	bNode->m_value=bData;
	bNode->m_left=NULL;
	bNode->m_right=NULL;
	/*cout<<bData<<endl;*/
	if(start==end)return bNode;
	int i=0;
	for( ;i<len-1 ;i++)
	{
		if(start[i]>bData)
		{
			break;
		}
	}
	if(i>len)return NULL;
	if(i>0)
	{
		//cout<<"构造左子树"/*<<bData*/<<endl;
		bNode->m_left=construtBinaryTree(start,start+i-1);
	}
		
	if(i<end-start)
	{
		//cout<<"构造右子树"/*<<bData*/<<endl;
		bNode->m_right=construtBinaryTree(start+i,end-1);
	}
	
	return bNode;
}
//后序遍历

//判断Tree是否包含subTree  先处理完左边的在处理右边的
bool doesTreeHasSubTree(Node *Tree,Node *subTree)
{
	if(subTree==NULL)return true;
	if(Tree==NULL)return false;

	if(subTree->m_value!=Tree->m_value)
		return false;

	return doesTreeHasSubTree(Tree->m_left,subTree->m_left)&&doesTreeHasSubTree(Tree->m_right,subTree->m_right);
}

//先找到B的根节点
bool hasSubTree(Node *Tree,Node *subTree)
{
	if(subTree==NULL)return true;
	if(Tree==NULL)return false;
	bool result=false;

	if(subTree&&Tree)
	{
		if(Tree->m_value==subTree->m_value)
		{
			result=doesTreeHasSubTree(Tree,subTree);
		}
		if(!result)
		{
			result=hasSubTree(Tree->m_left,subTree);
		}
		if(!result)
		{
			result=hasSubTree(Tree->m_right,subTree);
		}
	}
	return result;
}

//测试函数
//
//void main()
//{
//		Node *tree1=NULL;
//		int data[]={5,7,6,9,11,10,8};
//		int *pdata=data;
//		tree1=construtBinaryTree(pdata,pdata+6);
//
//		Node *tree2=NULL;
//		int data2[]={5,7,6};
//		int *pdata2=data2;
//		tree2=construtBinaryTree(pdata2,pdata2+2);
//
//		bool result=hasSubTree(tree1,tree2);
//
//		cout<<result<<endl;
//
//
//}