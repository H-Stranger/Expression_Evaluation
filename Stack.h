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

typedef char DataType_Oprt;//��������������
typedef double DataType_Oprd;//��������������

//��̬˳���ʵ��ջ
typedef struct
{
	DataType_Oprt* oprt;//����������
	int top;		//ջ��
	int capacity;	//����
}StackOprt;

typedef struct
{
	DataType_Oprd* oprd;//����������
	int top;
	int capacity;
}StackOprd;


//�ӿں���

//ջ��������

//��ʼ��������ջ
int Init_stackOprt(StackOprt* pOprt);
//��ʼ��������ջ
int Init_stackOprd(StackOprd* pOprd);

//�ж�ջ���������������
static void CheckCapacity_oprt(StackOprt* pOprt);
static void CheckCapacity_oprd(StackOprd* pOprd);

//��������ջ
int Push_stackOprt(StackOprt* pOprt, char c);
//��������ջ
int Push_stackOprd(StackOprd* pOprd, double c);

//��������ջ
int Pop_stackOprt(StackOprt* pOprt);
//��������ջ
int Pop_stackOprd(StackOprd* pOprd);

//��ò�����ջ��Ԫ��
DataType_Oprt Top_stackOprt(StackOprt* pOprt);
//��ò�����ջ��Ԫ��
DataType_Oprd Top_stackOprd(StackOprd* pOprd);

//��������

//�������ȼ�����
int Prior(char c);
//�жϲ�����
int Is_oprt(char c);
//�жϲ�����
int Is_oprd(char c);