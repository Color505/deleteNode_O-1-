#include "stdafx.h"
#include <iostream>
using namespace std;
//
typedef struct stack
{
	int m_value[100];
	int top;
	stack()
	{
		top=0;
		memset(m_value,0,100);
	}
	int pop()
	{
		if(top==0)
		{
			cout<<"栈为空"<<endl;
			return -1;
		}
		top--;
		return	m_value[top];
	}

	int push(int m)
	{
		/*cout<<top<<endl;*/
		m_value[top++]=m;
		
		if(top>100)
		{
			cout<<" 栈溢出"<<endl;
			return -1;
		}
		return m;
	}

	int min()
	{
		if(top==0)
		{
			cout<<"无最小值"<<endl;
			return 0;
		}
		int m=top-1;
		return m_value[m];
	}
}Stack;

class stackWithMin
{


public:
	stackWithMin();
	int pop();
	int push(int value);
	int min();
private:
	Stack m_min;
	Stack m_data;
	int m_minV;
};
stackWithMin::stackWithMin()
{
	m_minV=0xEFFF;//初始值最大
}
int stackWithMin::pop()
{
	m_min.pop();
	return m_data.pop();
}

int stackWithMin::push(int m)
{
	m_data.push(m);
	if(m<m_minV)
	{
		m_minV=m;
		m_min.push(m);
	}
	else
	{
		m_min.push(m_minV);
	}
	return 1;
}

int stackWithMin::min()
{
	return m_min.min();
}
//void main()
//{
//	int pushValue[4]={5,6,4,7};
//	stackWithMin *stkMin=new stackWithMin;
//	cout<<"进栈顺序："<<endl;
//	for(int i=0;i<sizeof(pushValue)/sizeof(int);i++)
//	{
//		stkMin->push(pushValue[i]);
//		cout<<pushValue[i]<<"进栈"<<endl;
//		cout<<"最小值:"<<stkMin->min()<<endl;
//	}
//	cout<<endl;
//	int a,b,c;
//	b=stkMin->pop();
//	cout<<"最小值:"<<stkMin->min()<<endl;
//	a=stkMin->pop();
//	cout<<"最小值:"<<stkMin->min()<<endl;
//	a=stkMin->pop();
//	cout<<"最小值:"<<stkMin->min()<<endl;
//	c=stkMin->push(0);
//	cout<<"最小值:"<<stkMin->min()<<endl;
//	//for(int i=0;i<sizeof(pushValue)/sizeof(int);i++)
//	//{
//	//	a=stkMin->min();
//	//	b=stkMin->pop();
//	//	cout<<"最小值："<<a<<" 弹出"<<b<<endl;
//	//}
//	
//	cout<<endl;
//
//}