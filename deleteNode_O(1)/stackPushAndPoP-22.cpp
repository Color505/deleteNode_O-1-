#include "stdafx.h"
#include <iostream>
using namespace std;
typedef struct ststack
{
	int m_value[100];
	int m_top;
	ststack()
	{
		m_top=0;
		memset(m_value,0,100);
	}
	int pop()
	{
		if(m_top==0)
		{
			cout<<"栈为空"<<endl;
			return -1;
		}
		m_top--;
		return	m_value[m_top];
	}

	int push(int m)
	{
		m_value[m_top++]=m;
		if(m_top>100)
		{
			cout<<" 栈溢出"<<endl;
			return -1;
		}
		return m;
	}
	int top()
	{
		int m=m_top-1;
		return m_value[m];
	}

	int size()
	{
		return m_top;
	}
}STstack;



bool IsPopOrder(const int *pPush,int *pPop,int nlen)
{
	if( pPop==NULL || nlen==0)return true;
	if(pPush==NULL)return false;
	STstack ststack;
	int popIdx=0;
	int i=0;
	while(ststack.size()!=0 ||i<nlen)
	{
		if(pPush[i]==pPop[popIdx])
		{
			cout<<"进栈："<<ststack.push(pPush[i])<<endl;
			cout<<"弹出：" <<ststack.pop()<<endl;
			popIdx++;
		}
		else if(ststack.top()==pPop[popIdx])
		{
			cout<<"弹出：" <<ststack.pop()<<endl;
			popIdx++;
		}
		else if(i<nlen)
		{
			cout<<"进栈：" <<ststack.push(pPush[i])<<endl;
		}
		else
		{
			cout<<"弹出：" <<ststack.pop()<<endl;
		}
		i++;
	}
	if(ststack.size()!=0 ||popIdx!=nlen)return false;
	return true;

}

bool IsPopOrder_22( int *pPush, int *pPop,int nlen)
{
	 int *pNextPush=pPush;
	 int *pNextPop=pPop;
	 STstack ststack;
	while(pNextPop-pPop<nlen)
	{
		while(ststack.size()==0|| ststack.top()!=*pNextPop)
		{
			if(pNextPush-pPush==nlen)break;
			ststack.push(*pNextPush);
			pNextPush++;
		}
		if(ststack.top()!=*pNextPop)break;
		ststack.pop();
		pNextPop++;
	}

	if(ststack.size()==0&&pNextPop-pPop==nlen)return true;
	else return false;

}
//void main()
//{
//	int pPush[5]={1,2,3,4,5};
//	int pPop[5]={4,5,3,1,2};
//	
//	bool ispoporder2=IsPopOrder_22(pPush,pPop,5);
//	bool ispoporder=IsPopOrder(pPush,pPop,5);
//	cout<<endl;
//
//}