#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//初始化操作符栈
int Init_stackOprt(StackOprt* pOprt)
{
	//栈不存在
	if (pOprt == NULL)
		return NO;//失败
	
	pOprt->oprt = NULL;
	pOprt->capacity = 0;//初始空间为0
	pOprt->top = 0;
	
	return OK;
}
//初始化操作数栈
int Init_stackOprd(StackOprd* pOprd)
{
	//栈不存在
	if (pOprd == NULL)
		return NO;//失败

	pOprd->oprd = NULL;
	pOprd->capacity = 0;//初始空间为0
	pOprd->top = 0;
	
	return OK;
}

//操作符相关函数

//判断栈满，若满则扩容
static void CheckCapacity_oprt(StackOprt* pOprt)
{
	if (pOprt->capacity == pOprt->top)
	{
		//判断空间是否为0，若是初始空间为4，若不是则赋为原来空间的2倍
		int newCapacity = pOprt->capacity == 0 ? 4 : 2 * (pOprt->capacity);
		//给操作符数组开辟动态空间
		DataType_Oprt* tmp = (DataType_Oprt*)realloc(pOprt->oprt, newCapacity * sizeof(DataType_Oprt));
		//空间是否开辟成功
		if (tmp == NULL)
		{
			printf("Realloc failed\n");
			exit(-1);
		}
		else
		{
			pOprt->oprt = tmp;
			pOprt->capacity = newCapacity;
		}
	}
}

//操作符入栈
int Push_stackOprt(StackOprt* pOprt, char c)
{
	//判断栈存在
	if (pOprt == NULL)
		return NO;//失败

	//判断空间是否够，不够就增
	CheckCapacity_oprt(pOprt);
	//栈顶赋值
	pOprt->oprt[pOprt->top] = c;
	pOprt->top++;

	return OK;//成功
}

//操作符出栈
int Pop_stackOprt(StackOprt* pOprt)
{
	//栈长为0，则不能出栈
	if (pOprt == NULL || pOprt->top <= 0)
		return NO;//失败
	pOprt->top--;
	return OK;
}

//获得操作符栈顶元素
DataType_Oprt Top_stackOprt(StackOprt* pOprt)
{
	assert(pOprt);//直接断言判断栈存在
	//栈顶元素为top-1
	return pOprt->oprt[pOprt->top - 1];
}

//判断操作符栈空
bool isEmpty_stackOprt(StackOprt* pOprt)
{
	assert(pOprt);//直接断言判断栈存在
	return pOprt->top == 0;//空则true
}


//操作数相关函数

//判断栈满，若满则扩容
static void CheckCapacity_oprd(StackOprd* pOprd)
{
	if (pOprd->capacity == pOprd->top)
	{
		//判断空间是否为0，若是初始空间为4，若不是则赋为原来空间的2倍
		int newCapacity = pOprd->capacity == 0 ? 4 : 2 * (pOprd->capacity);
		//给操作符数组开辟动态空间
		DataType_Oprd* tmp = (DataType_Oprt*)realloc(pOprd->oprd, newCapacity * sizeof(DataType_Oprd));
		//空间是否开辟成功
		if (tmp == NULL)
		{
			printf("Realloc failed\n");
			exit(-1);
		}
		else
		{
			pOprd->oprd = tmp;
			pOprd->capacity = newCapacity;
		}
	}
}

//操作数入栈
int Push_stackOprd(StackOprd* pOprd, double d)
{
	//判断栈存在
	if (pOprd == NULL)
		return NO;//失败

	//判断空间是否够，不够就增
	CheckCapacity_oprd(pOprd);
	//栈顶赋值
	pOprd->oprd[pOprd->top] = d;
	pOprd->top++;

	return OK;//成功
}

//操作数出栈
int Pop_stackOprd(StackOprd* pOprd)
{
	//栈长为0，则不能出栈
	if (pOprd == NULL || pOprd->top <= 0)
		return NO;//失败
	pOprd->top--;
	return OK;
}

//获得操作数栈顶元素
DataType_Oprd Top_stackOprd(StackOprd* pOprd)
{
	assert(pOprd);//直接断言判断栈存在
	//栈顶元素为top-1
	return pOprd->oprd[pOprd->top - 1];
}

//判断操作数栈空
bool isEmpty_stackOprd(StackOprd* pOprd)
{
	assert(pOprd);//直接断言判断栈存在
	return pOprd->top == 0;//空则true
}


//操作函数

//返回优先级函数
int Prior(char c)
{
	switch (c)
	{
	case '#': return -1; break;//结束
	case '+': return 2; break;
	case '-': return 2; break;
	case '*': return 3; break;
	case '/': return 3; break;
	case '%': return 3; break;//取余
	case '^': return 4; break;//幂
	case '(': return 0; break;
	case ')': return 1; break;
	default:
	{
		printf("优先级寻找失败\n");
		break;
	}
	}
	return -1;
}

//判断操作符
int Is_oprt(char c)
{
	int i = 0;
	char s[9] = { '+', '-', '*' , '/','%', '^', '(', ')','#'};
	//遍历判断
	for (i = 0; i < 9; i++)
	{
		if (s[i] == c)
			return OK;
	}

	return NO;
}

//判断操作数
int Is_oprd(char c)
{
	if (c >= '0' && c <= '9')
		return OK;
	return NO;
}



