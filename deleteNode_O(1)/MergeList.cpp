#include"stdafx.h"
#include<iostream>
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

extern Node* insertNode(Node **headNode,int value);

Node* mergeList(Node *headList1,Node *headList2)
{

	if(headList1==NULL)return headList2;
	if(headList2==NULL)return headList1;

	Node *p1=headList1;
	Node *p2=headList2;
	Node *sortList=NULL,*_p=NULL;
	if(p1->value<=p2->value)// �Ƚϵ�һ��Ԫ�� �ϲ���ȷ������ͷָ��
	{
		sortList=p1;
		_p=p1;
		p1=p1->next;

	}
	else
	{
		sortList=p2;
		_p=p2;
		p2=p2->next;
	}

	while(p1!=NULL &&p2!=NULL)//�����Ÿ��ݴ�С��ϵ�ȽϺ����Ԫ��
	{
		if(p1->value<=p2->value)
		{
			_p->next=p1;
			p1=p1->next;
			_p=_p->next;
		}
		else
		{
			_p->next=p2;
			p2=p2->next;
		   _p=_p->next;
		}
	}
	if(p1==NULL)_p->next=p2;//p1�� ��p2���ӵ�����
	if(p2==NULL)_p->next=p1;//p2�� ��p1���ӵ�����
	return sortList;

}

Node* mergeLst(Node *headList1,Node *headList2)//�ݹ����
{
	if(headList1==NULL) return headList2;
	if(headList2==NULL)return headList1;
	Node *sortList=NULL;
	if(headList1->value<=headList2->value)
	{
		sortList=headList1;
		sortList->next=mergeLst(headList1->next,headList2);
	}

	else 
	{
		sortList=headList2;
		sortList->next=mergeLst(headList1,headList2->next);
	}

	return sortList;
}

//int _tmain(int argc, _TCHAR* argv[])
//{
//	Node *headNode1=NULL;
//	insertNode(&headNode1,0);//ͷ���
//	insertNode(&headNode1,1);//c����1
//	insertNode(&headNode1,3);
//	insertNode(&headNode1,6);
//
//
//	Node *headNode2=NULL;
//	insertNode(&headNode2,2);
//	insertNode(&headNode2,5);
//	insertNode(&headNode2,6);
//	insertNode(&headNode2,7);
//	insertNode(&headNode2,9);
//
//	Node *mergelst= mergeLst(headNode1,headNode2);//�ݹ�
//	Node *mergelst= mergeList(headNode1,headNode2);//�ǵݹ�
//	while(mergelst!=NULL)
//	{
//		cout<<mergelst->value<<" ";
//		mergelst=mergelst->next;
//	}
//	return 0;
//}