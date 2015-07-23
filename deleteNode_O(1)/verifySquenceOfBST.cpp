#include "stdafx.h"
#include <iostream>
using namespace std;

bool verifySquenceOfBST(int sequence[],int len)
{

	if(sequence==NULL || len<=0)return false;
	int endval=sequence[len-1];
	int i=0;
	for(i=0;i<len-1;i++)
	{
		if(sequence[i]>endval)
		{
			break;
		}
		
	}
	int j=i;
	
	for(;j<len-1;j++)
	{
		if(sequence[j]<endval)
		{
			return false;
		}
	}
	bool left=true;
	if(i>0)//i!=0 如果等于0了 就没有左子树 不需要递归
	{
		left=verifySquenceOfBST(sequence,i);
	}
	bool right=true;
	if(i<len-1)
	{
		right=verifySquenceOfBST(sequence+i,len-i-1);
	}
	return left&&right;
}


//void main()
//{
//		
//		int sequence[]={5,7,6,9,11,10,8};
//		bool flag=verifySquenceOfBST(sequence,7);
//	
//}