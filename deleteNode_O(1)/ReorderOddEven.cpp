#include"stdafx.h"
#include<iostream>
using namespace std;


//������ǰ�� ż���ں���
void reorderOddEven(int *data,int len)
{
	int first=0;
	int last=len-1;

	while(first<last)
	{
		while(data[first]&0x01)//����
			first++;
	
		while(!(data[last]&0x01))//  ż��
			last--;

		if(first<last)
		{
			int temp;
			temp=data[first];
			data[first]=data[last];
			data[last]=temp;
		}
	
	}
}

bool Odd(int data)
{
	return data&0x01;
}


//�ú���������ʵ���ж�����ż��
void _reorderOddEven(int *data,int len,bool (*Odd)(int))
{

	if(data==NULL||len<=0)
		return;
	int first=0;
	int last=len-1;

	while(first<last)
	{
		while(Odd(data[first]))//����
			first++;
	
		while(!Odd(data[last]))//  ż��
			last--;

		if(first<last)
		{
			int temp;
			temp=data[first];
			data[first]=data[last];
			data[last]=temp;
		}
	
	}
}

//
//int _tmain(int argc, _TCHAR* argv[])
//{
//	int data[10];
//
//	for(int i=0 ;i<sizeof(data)/sizeof(int) ;i++)
//	{
//		data[i]=i+1;
//	}
//	
//	for(int i=0 ;i<sizeof(data)/sizeof(int) ;i++)
//	{
//		cout<<data[i]<<" ";
//	}
//	cout<<endl;
//	_reorderOddEven(data,sizeof(data)/sizeof(int),Odd);
//
//	for(int i=0 ;i<sizeof(data)/sizeof(int) ;i++)
//	{
//		cout<<data[i]<<" ";
//	}
//	cout<<endl;
//	return 0;
//}