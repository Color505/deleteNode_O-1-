// deleteNode_O(1).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct node
{
	int value;
	struct node *next;
	node()
	{
		value=0;
		next=NULL;
	}

}Node;

Node* insertNode(Node **headNode,int value)
{


	Node *pNew=new Node();
	pNew->value=value;
	pNew->next=NULL;
	if(*headNode==NULL)
	{
		*headNode=pNew;
		pNew->value=value;
	}
	else
	{
		Node *pNode=*headNode;
		//pNode->value++;
		while(pNode->next!=NULL)
		pNode=pNode->next;
		pNode->next=pNew;
	}
	return *headNode;

}


void deleteNode(Node **headNode,Node *p)
{

	if(*headNode==NULL || p==NULL)return;
	Node *pnode=*headNode;
	if(*headNode==p)//ɾ����һ���ڵ�
	{
		delete p;
		p=NULL;
		*headNode=NULL;
	}
	else if(p->next==NULL)//ɾ�����һ���ڵ�
	{
		while(pnode->next!=p)
		pnode=pnode->next;
		delete p;
		p=NULL;
		pnode->next=NULL;
	}
	else // ɾ���м�ľ���ڵ�
	{
		Node *_p=p->next;
		p->value=_p->value;
		p->next=_p->next;
		delete _p;
		_p=NULL;
		cout<<"delete success!"<<endl;
	}
	return ;
}

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	Node *headNode=NULL;
//
//	insertNode(&headNode,0);//ͷ���
//	insertNode(&headNode,1);//c����1
//	insertNode(&headNode,3);
//	insertNode(&headNode,2);
//	insertNode(&headNode,4);
//	insertNode(&headNode,5);
//	insertNode(&headNode,6);
//	insertNode(&headNode,7);
//	insertNode(&headNode,9);
//
//	Node *p=headNode;//ɾ��ͷ
//
//	while(p->next->value!=5)
//		p=p->next;
//	deleteNode(&headNode,p);
//
//
//	return 0;
//}

