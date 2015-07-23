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

Node *reverseLink(Node **headNode)
{
	if(*headNode==NULL)return NULL;


	Node *pNode=NULL;
	Node *curNode=*headNode;
	Node *backNode=NULL;

	while(curNode!=NULL)
	{
		if(curNode->next!=NULL)
		{
			backNode=curNode->next;//�����һ���ڵ�
			curNode->next=pNode;//��ǰ�ڵ����ӵ�ǰһ���ڵ�
			pNode=curNode;//ǰһ���ڵ����
			curNode=backNode;//��ǰ�ڵ����
		}
		else
		{
			curNode->next=pNode;//���һ���ڵ�
			break;
		}
	}
	return curNode;
}

//void main()
//{
//		Node *headNode=NULL;
//		insertNode(&headNode,0);//ͷ���
//		insertNode(&headNode,1);//c����1
//		insertNode(&headNode,3);
//		insertNode(&headNode,2);
//		insertNode(&headNode,4);
//		insertNode(&headNode,5);
//		insertNode(&headNode,6);
//		insertNode(&headNode,7);
//		insertNode(&headNode,9);
//		
//		cout<<"��תǰ��";
//		Node *_p=headNode;
//		while(_p!=NULL)
//		{
//			cout<<_p->value<<" ";
//			_p=_p->next;
//
//		}
//		cout<<endl;
//		headNode=reverseLink(&headNode);
//		cout<<"��ת��";
//		_p=headNode;
//		while(_p!=NULL)
//		{
//			cout<<_p->value<<" ";
//			_p=_p->next;
//
//		}
//}