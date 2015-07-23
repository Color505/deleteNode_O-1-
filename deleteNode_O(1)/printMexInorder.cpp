#include "stdafx.h"
#include <iostream>
using namespace std;

void printMatrixCircle(int **array,int col,int row,int start)
{
	int endx=col-start-1;
	int endy=row-start-1;


	for(int i=start;i<=endx;i++)//上
	{
		cout<<array[start][i]<<" ";
	}

	if(endy>start)//右
	{
		for(int i=start+1;i<=endy;i++)
		{
			cout<<array[i][endx]<<" ";
		}
	}
	if(endx>start&&endy>start)//下
	{
		for(int i=endx-1;i>=start;i--)
		{
			cout<<array[endy][i]<<" ";
		}
	}

	if(endx>start)//左
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
 //二维指针做参数传递



//参考：
/*


实参                                                      所匹配的形参

数组的数组          char c[8][10];                 char (*)[10];          数组指针

指针数组             char *c[10];                   char **c;               指针的指针

数组指针(行指针)  char (*c)[10];                 char (*c)[10];        不改变

指针的指针           char **c;                       char **c;               不改变

下面再看一个网友的一段分析相当给力的代码：

#include "stdafx.h" 
#include <iostream> 
using namespace std; 
 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
    int arr1[3]; 
    int arr2[3]; 
    int arr3[3]; 
    int * ptr; 
    // ptr1是一个指向 int [3] 的指针，即ptr的类型和&arr1的类型是一样的，注意：arr1指向的内存区域定长 
    int ptr1[3][3]={{1,2,3},{1,2,3},{1,2,3}}; 
    // ptr2是一个指向 int * 的指针，即ptr2的类型和&ptr是一样的，注意：ptr指向的内存区域不定长 
    int * ptr2[3]={arr1,arr2,arr3}; 
    // ptr3是一个指向 int [3] 的指针，即ptr3的类型和&arr1的类型是一样的，注意：arr1指向的内存区域定长 
    int(* ptr3)[3]=&arr1; 
    ptr3=ptr1; // 没错，他们的类型相同 
 // ptr3=ptr2;//error 无法从“int *[3]”转换为“int (*)[3] 
 // ptr4是一个指向 int * 的指针，即ptr4的类型和&ptr是一样的，注意：ptr指向的内存区域不定长 
    int ** ptr4; 
    //ptr4=&arr1; //error 无法从“int (*)[3]”转换为“int ** 
    ptr4=ptr2; // 没错，他们的类型相同 
 //ptr4=ptr3; // error 无法从“int (*)[3]”转换为“int ** 
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