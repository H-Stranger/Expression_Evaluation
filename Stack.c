#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//��ʼ��������ջ
int Init_stackOprt(StackOprt* pOprt)
{
	//ջ������
	if (pOprt == NULL)
		return NO;//ʧ��
	
	pOprt->oprt = NULL;
	pOprt->capacity = 0;//��ʼ�ռ�Ϊ0
	pOprt->top = 0;
	
	return OK;
}
//��ʼ��������ջ
int Init_stackOprd(StackOprd* pOprd)
{
	//ջ������
	if (pOprd == NULL)
		return NO;//ʧ��

	pOprd->oprd = NULL;
	pOprd->capacity = 0;//��ʼ�ռ�Ϊ0
	pOprd->top = 0;
	
	return OK;
}

//��������غ���

//�ж�ջ��������������
static void CheckCapacity_oprt(StackOprt* pOprt)
{
	if (pOprt->capacity == pOprt->top)
	{
		//�жϿռ��Ƿ�Ϊ0�����ǳ�ʼ�ռ�Ϊ4����������Ϊԭ���ռ��2��
		int newCapacity = pOprt->capacity == 0 ? 4 : 2 * (pOprt->capacity);
		//�����������鿪�ٶ�̬�ռ�
		DataType_Oprt* tmp = (DataType_Oprt*)realloc(pOprt->oprt, newCapacity * sizeof(DataType_Oprt));
		//�ռ��Ƿ񿪱ٳɹ�
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

//��������ջ
int Push_stackOprt(StackOprt* pOprt, char c)
{
	//�ж�ջ����
	if (pOprt == NULL)
		return NO;//ʧ��

	//�жϿռ��Ƿ񹻣���������
	CheckCapacity_oprt(pOprt);
	//ջ����ֵ
	pOprt->oprt[pOprt->top] = c;
	pOprt->top++;

	return OK;//�ɹ�
}

//��������ջ
int Pop_stackOprt(StackOprt* pOprt)
{
	//ջ��Ϊ0�����ܳ�ջ
	if (pOprt == NULL || pOprt->top <= 0)
		return NO;//ʧ��
	pOprt->top--;
	return OK;
}

//��ò�����ջ��Ԫ��
DataType_Oprt Top_stackOprt(StackOprt* pOprt)
{
	assert(pOprt);//ֱ�Ӷ����ж�ջ����
	//ջ��Ԫ��Ϊtop-1
	return pOprt->oprt[pOprt->top - 1];
}

//�жϲ�����ջ��
bool isEmpty_stackOprt(StackOprt* pOprt)
{
	assert(pOprt);//ֱ�Ӷ����ж�ջ����
	return pOprt->top == 0;//����true
}


//��������غ���

//�ж�ջ��������������
static void CheckCapacity_oprd(StackOprd* pOprd)
{
	if (pOprd->capacity == pOprd->top)
	{
		//�жϿռ��Ƿ�Ϊ0�����ǳ�ʼ�ռ�Ϊ4����������Ϊԭ���ռ��2��
		int newCapacity = pOprd->capacity == 0 ? 4 : 2 * (pOprd->capacity);
		//�����������鿪�ٶ�̬�ռ�
		DataType_Oprd* tmp = (DataType_Oprt*)realloc(pOprd->oprd, newCapacity * sizeof(DataType_Oprd));
		//�ռ��Ƿ񿪱ٳɹ�
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

//��������ջ
int Push_stackOprd(StackOprd* pOprd, double d)
{
	//�ж�ջ����
	if (pOprd == NULL)
		return NO;//ʧ��

	//�жϿռ��Ƿ񹻣���������
	CheckCapacity_oprd(pOprd);
	//ջ����ֵ
	pOprd->oprd[pOprd->top] = d;
	pOprd->top++;

	return OK;//�ɹ�
}

//��������ջ
int Pop_stackOprd(StackOprd* pOprd)
{
	//ջ��Ϊ0�����ܳ�ջ
	if (pOprd == NULL || pOprd->top <= 0)
		return NO;//ʧ��
	pOprd->top--;
	return OK;
}

//��ò�����ջ��Ԫ��
DataType_Oprd Top_stackOprd(StackOprd* pOprd)
{
	assert(pOprd);//ֱ�Ӷ����ж�ջ����
	//ջ��Ԫ��Ϊtop-1
	return pOprd->oprd[pOprd->top - 1];
}

//�жϲ�����ջ��
bool isEmpty_stackOprd(StackOprd* pOprd)
{
	assert(pOprd);//ֱ�Ӷ����ж�ջ����
	return pOprd->top == 0;//����true
}


//��������

//�������ȼ�����
int Prior(char c)
{
	switch (c)
	{
	case '#': return -1; break;//����
	case '+': return 2; break;
	case '-': return 2; break;
	case '*': return 3; break;
	case '/': return 3; break;
	case '%': return 3; break;//ȡ��
	case '^': return 4; break;//��
	case '(': return 0; break;
	case ')': return 1; break;
	default:
	{
		printf("���ȼ�Ѱ��ʧ��\n");
		break;
	}
	}
	return -1;
}

//�жϲ�����
int Is_oprt(char c)
{
	int i = 0;
	char s[9] = { '+', '-', '*' , '/','%', '^', '(', ')','#'};
	//�����ж�
	for (i = 0; i < 9; i++)
	{
		if (s[i] == c)
			return OK;
	}

	return NO;
}

//�жϲ�����
int Is_oprd(char c)
{
	if (c >= '0' && c <= '9')
		return OK;
	return NO;
}



