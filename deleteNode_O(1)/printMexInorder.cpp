#include "stdafx.h"
#include <iostream>
using namespace std;

void printMatrixCircle(int **array,int col,int row,int start)
{
	int endx=col-start-1;
	int endy=row-start-1;


	for(int i=start;i<=endx;i++)//��
	{
		cout<<array[start][i]<<" ";
	}

	if(endy>start)//��
	{
		for(int i=start+1;i<=endy;i++)
		{
			cout<<array[i][endx]<<" ";
		}
	}
	if(endx>start&&endy>start)//��
	{
		for(int i=endx-1;i>=start;i--)
		{
			cout<<array[endy][i]<<" ";
		}
	}

	if(endx>start)//��
	{
		for(int i=endy-1;i>start;i--)
		{
			cout<<array[i][start]<<" ";
		}
	}
	
}
void printMatrinxInorder(int **array,int col,int row)
{
	
	int start=0;
	for(;col>2*start&&row>2*start;start++)
	{
		printMatrixCircle(array,col,row,start);

	}
}
 //��άָ������������



//�ο���
/*


ʵ��                                                      ��ƥ����β�

���������          char c[8][10];                 char (*)[10];          ����ָ��

ָ������             char *c[10];                   char **c;               ָ���ָ��

����ָ��(��ָ��)  char (*c)[10];                 char (*c)[10];        ���ı�

ָ���ָ��           char **c;                       char **c;               ���ı�

�����ٿ�һ�����ѵ�һ�η����൱�����Ĵ��룺

#include "stdafx.h" 
#include <iostream> 
using namespace std; 
 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
    int arr1[3]; 
    int arr2[3]; 
    int arr3[3]; 
    int * ptr; 
    // ptr1��һ��ָ�� int [3] ��ָ�룬��ptr�����ͺ�&arr1��������һ���ģ�ע�⣺arr1ָ����ڴ����򶨳� 
    int ptr1[3][3]={{1,2,3},{1,2,3},{1,2,3}}; 
    // ptr2��һ��ָ�� int * ��ָ�룬��ptr2�����ͺ�&ptr��һ���ģ�ע�⣺ptrָ����ڴ����򲻶��� 
    int * ptr2[3]={arr1,arr2,arr3}; 
    // ptr3��һ��ָ�� int [3] ��ָ�룬��ptr3�����ͺ�&arr1��������һ���ģ�ע�⣺arr1ָ����ڴ����򶨳� 
    int(* ptr3)[3]=&arr1; 
    ptr3=ptr1; // û�����ǵ�������ͬ 
 // ptr3=ptr2;//error �޷��ӡ�int *[3]��ת��Ϊ��int (*)[3] 
 // ptr4��һ��ָ�� int * ��ָ�룬��ptr4�����ͺ�&ptr��һ���ģ�ע�⣺ptrָ����ڴ����򲻶��� 
    int ** ptr4; 
    //ptr4=&arr1; //error �޷��ӡ�int (*)[3]��ת��Ϊ��int ** 
    ptr4=ptr2; // û�����ǵ�������ͬ 
 //ptr4=ptr3; // error �޷��ӡ�int (*)[3]��ת��Ϊ��int ** 
    return 0; 

*/
//void main()
//{
//	int value1[3]={1,2,3};
//	int value2[3]={2,3,4};
//	int value3[3]={3,4,5};
//	int value4[3]={3,4,5};
//	int *prorder[4]={value1,value2,value3,value4};
//	printMatrinxInorder(prorder,3,4);
//	cout<<endl;
//
//}