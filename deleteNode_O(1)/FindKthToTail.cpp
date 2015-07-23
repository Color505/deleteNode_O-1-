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
//Node* insertNode(Node **headNode,int value)
//{
//
//
//	Node *pNew=new Node();
//	pNew->value=value;
//	pNew->next=NULL;
//	if(*headNode==NULL)
//	{
//		*headNode=pNew;
//		pNew->value=0;
//	}
//	else
//	{
//		Node *pNode=*headNode;
//		pNode->value++;
//		while(pNode->next!=NULL)
//		pNode=pNode->next;
//		pNode->next=pNew;
//	}
//	return *headNode;
//
//}
extern Node* insertNode(Node **headNode,int value);
Node * findKthToTail(Node **headNode,int k)
{
	if(*headNode==NULL||k==0)return NULL;

	Node *p1=*headNode,*p2=*headNode;
	while(--k)//����K��ֵ�ж��������Ƿ����
	{
		if(p2!=NULL)
		{
			p2=p2->next;
		}
		else
		{
			break;
		}
	}
	
	if(k!=0)
	{
		cout<<"K����������,������K���ڵ㲻����" <<endl;
		return NULL;
	}
	else
	{
		while(p2->next!=NULL)
		{
			p1=p1->next;
			p2=p2->next;
		}

		return p1;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	Node *headNode=NULL;
	//insertNode(&headNode,0);//ͷ���
	insertNode(&headNode,1);//c����1
	insertNode(&headNode,3);
	insertNode(&headNode,2);
	insertNode(&headNode,4);
	insertNode(&headNode,5);


	Node *p=findKthToTail(&headNode,3);
	if(p==NULL)
	{
		cout<<"������С��K��ֵ"<<endl;
		return 1;
	}
	cout<<p->value<<endl;
	return 0;
}