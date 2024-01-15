#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//���㺯��		��������������������ȷ��������
double Calculate(char c, double L, double R)
{
	switch (c)
	{
	case '+': return (L + R);
	case '-': return L - R;
	case '*': return L * R;
	case '/':
	{
		if (0 == R)
		{
			printf("��������Ϊ0��\n");
			exit(-1);//����ֱ�ӽ�������
		}
		else
			return L / R;
	}
	case '^': return pow(L, R);
	case '%': return (int)L % (int)R;
	default:
	{
		printf("�ݲ��ṩ��%c��֧��!\n", c);
		return 0;
	}

	}
}

//���ܣ�����������ջ���������Ͳ�����ջ��һ���������������㣬������������������ջ
void stackCal(StackOprt* poprt, StackOprd* poprd)
{
	double R = Top_stackOprd(poprd);//��ʽ�ұ���ջ��
	Pop_stackOprd(poprd);//��ջ

	double L = Top_stackOprd(poprd);
	Pop_stackOprd(poprd);
	//����
	double res = Calculate(Top_stackOprt(poprt), L, R);
	Pop_stackOprt(poprt);//����������
	//��������ջ
	printf("%lf��������������ջ>\n", res);
	Push_stackOprd(poprd, res);
}

//���ܣ�չʾ���ʽ�������
void Print(char* pc)
{
	Sleep(1000);
	int i;
	for (i = 0; pc[i]; i++)
	{
		printf("%c", pc[i]);
	}
	printf("\n");
}


void GetAns()
{
	//�����ṹ�� ��ʼ��
	StackOprt oprt;
	StackOprd oprd;
	Init_stackOprd(&oprd);
	Init_stackOprt(&oprt);

	printf("��������ʽ:>(��#��ͷ��β)\n");
	//���ձ��ʽ
	char str[MAX_SIZE];
	gets(str);

	char* p = str;//����ָ�봦���ַ�����
	double num = 0;//������ַ�ת����λ��
	while (*p != '\0')
	{
		//�жϲ�����
		if (Is_oprd(*p))
		{
			num = num * 10 + (*p - '0');
			if (Is_oprd(*(p+1)))//�����һ���ַ�Ҳ�ǲ�����
			{
				p++;
				continue;	//���������жϣ�numֵ����
			}
			//�����ջ
			Push_stackOprd(&oprd, num);
			num = 0;
		}
		else if (Is_oprt(*p))
		{
			//��ʼ'#'��ջ �����ŵ����ж���ջ
			if (*p == '#' && oprd.top == 0 || *p=='(')
			{
				Push_stackOprt(&oprt, *p);
			}
			else if (*p == ')')
			{
				//ͬ��������˼·��ֻ���ж�������һ��
				while (Top_stackOprt(&oprt) != '(')
				{
					stackCal(&oprt, &oprd);
				}
				Pop_stackOprt(&oprt);//�����ŵ���ȥ
			}
			else if (*p == '#' && oprt.oprt[0] == '#')
			{
				while (Top_stackOprt(&oprt) != '#')
				{
					stackCal(&oprt, &oprd);
				}
			}
			//���ȼ���ջ��Ԫ����С���ַ���������
			else if (Prior(Top_stackOprt(&oprt)) < Prior(*p))
			{
				Push_stackOprt(&oprt, *p);
			}
			else if (Prior(Top_stackOprt(&oprt)) >= Prior(*p))
			{
				//��ǰ������ջ�������Ԫ�ض�����ֱ��#
				stackCal(&oprt, &oprd);
				Push_stackOprt(&oprt, *p);
			}
		}
		//��������ո��ж���������
		Print(p);
		p++;//ֱ�ӷŵ�ĩβ
	}
	printf("��������%lf\n", Top_stackOprd(&oprd));
}


void menu()
{
	printf("*****************************************\n");
	printf("***********    1.���ʽ��ֵ   ***********\n");
	printf("***********     2.���贴��    ***********\n");
	printf("***********       0.�˳�      ***********\n");
	printf("*****************************************\n");
}
void ShowInfo()
{
	printf("\n");
	printf("*****************************************\n");
	printf(" >Class: 22���������ѧ�뼼��רҵ        \n");
	printf(" >Author:  ���㶫   ����                 \n");
	printf(" >Created Time: 2024��1��15��    ����һ  \n");
	printf("*****************************************\n");
	printf("\n");
}

int main()
{
	int input;
	do 
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			getchar();
			GetAns();
			break;
		}
		case 2:
			ShowInfo();
			break;
		case 0:
			printf("�˳�\n");
			break;
		}
	} while (input);
	
	return 0;
}
