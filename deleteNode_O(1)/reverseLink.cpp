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
			backNode=curNode->next;//保存后一个节点
			curNode->next=pNode;//当前节点链接到前一个节点
			pNode=curNode;//前一个节点后移
			curNode=backNode;//当前节点后移
		}
		else
		{
			curNode->next=pNode;//最后一个节点
			break;
		}
	}
	return curNode;
}

//void main()
//{
//		Node *headNode=NULL;
//		insertNode(&headNode,0);//头结点
//		insertNode(&headNode,1);//c插入1
//		insertNode(&headNode,3);
//		insertNode(&headNode,2);
//		insertNode(&headNode,4);
//		insertNode(&headNode,5);
//		insertNode(&headNode,6);
//		insertNode(&headNode,7);
//		insertNode(&headNode,9);
//		
//		cout<<"反转前：";
//		Node *_p=headNode;
//		while(_p!=NULL)
//		{
//			cout<<_p->value<<" ";
//			_p=_p->next;
//
//		}
//		cout<<endl;
//		headNode=reverseLink(&headNode);
//		cout<<"反转后：";
//		_p=headNode;
//		while(_p!=NULL)
//		{
//			cout<<_p->value<<" ";
//			_p=_p->next;
//
//		}
//}