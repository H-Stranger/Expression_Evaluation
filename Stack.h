#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<math.h>
#include<windows.h>

#define MAX_SIZE 100
#define OK 1
#define NO 0

typedef char DataType_Oprt;//操作符数据类型
typedef double DataType_Oprd;//操作数数据类型

//动态顺序表实现栈
typedef struct
{
	DataType_Oprt* oprt;//操作符数组
	int top;		//栈顶
	int capacity;	//容量
}StackOprt;

typedef struct
{
	DataType_Oprd* oprd;//操作数数组
	int top;
	int capacity;
}StackOprd;


//接口函数

//栈基础函数

//初始化操作符栈
int Init_stackOprt(StackOprt* pOprt);
//初始化操作数栈
int Init_stackOprd(StackOprd* pOprd);

//判断栈满，如果满则扩容
static void CheckCapacity_oprt(StackOprt* pOprt);
static void CheckCapacity_oprd(StackOprd* pOprd);

//操作符入栈
int Push_stackOprt(StackOprt* pOprt, char c);
//操作数入栈
int Push_stackOprd(StackOprd* pOprd, double c);

//操作符出栈
int Pop_stackOprt(StackOprt* pOprt);
//操作数出栈
int Pop_stackOprd(StackOprd* pOprd);

//获得操作符栈顶元素
DataType_Oprt Top_stackOprt(StackOprt* pOprt);
//获得操作数栈顶元素
DataType_Oprd Top_stackOprd(StackOprd* pOprd);

//操作函数

//返回优先级函数
int Prior(char c);
//判断操作符
int Is_oprt(char c);
//判断操作数
int Is_oprd(char c);