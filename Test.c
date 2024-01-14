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
void Run_test()
{
	////�����������Ͳ������ṹ��
	//StackOprt oprt;
	//StackOprd oprd;
	//Init_stackOprt(&oprt);
	//Init_stackOprd(&oprd);
	//printf("%d\n", Init_stackOprd(&oprt));
	////��ջ����
	//printf("%d\n", Push_stackOprt(&oprt, 'c'));
	//printf("%d\n", Push_stackOprt(&oprt, 'd'));
	//printf("%d\n", Push_stackOprt(&oprt, 'e'));

	////��ջ����
	//printf("%d\n", Pop_stackOprt(&oprt));

	//printf("%c\n", Top_stackOprt(&oprt));//ջ������
	//printf("%d\n", Pop_stackOprt(&oprt));

	//printf("%c\n", oprt.oprt[oprt.top - 1]);

	//printf("%d\n", Pop_stackOprt(&oprt));
	//printf("%d\n", Pop_stackOprt(&oprt));//ջ��
	//printf("%d\n", isEmpty_stackOprt(&oprt));//�ж�ջ�ղ���


	//printf("--------------------------------\n");

	////���Է������ȼ�
	//printf("%d\n",Prior('+'));
	////������
	//printf("%d\n",Is_oprt(')'));

	////���㺯������
	//printf("%f\n", Calculate('+', 2, 3));
	//printf("%lf\n", Calculate('^', 2, 4));
	////printf("%lf\n", Calculate('/', 2, 0));
	//printf("��ʾ��С��ȡ���ֱ�ӱ�������������\n");
	//printf("%lf\n", Calculate('%', 9.3, 2));
	//printf("end\n");

}

void GetAns()
{
	StackOprt oprt;
	StackOprd oprd;
	Init_stackOprd(&oprd);
	Init_stackOprt(&oprt);

	char str[MAX_SIZE];
	gets(str);

	char* p = str;//ͨ�������ַ����
	int num = 0;//����������
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
			num = 0;
			int res = Push_stackOprd(&oprd, num);
			//p++;
		}
		else if (Is_oprt(*p))
		{
			//���ȼ���ջ��Ԫ����С���ַ���������
			if (*p == '(' || Prior(Top_stackOprt(&oprt)) < Prior(*p))
			{
				Push_stackOprt(&oprt, *p);
				
				//ջ��Ԫ�غ��ַ�����Ϊ#����
				if (Top_stackOprt(&oprt) == '#' && *p == '#')
					return Top_stackOprd(&oprd);//���ռ���Ľ��
			}
			else if (Prior(&oprt) >= Prior(*p))
			{
				//��ǰ������ջ�������Ԫ�ض�����ֱ��#
				while (Top_stackOprd(&oprt) != '#')
				{
					double R = Top_stackOprd(&oprd);//��ʽ�ұ���ջ��
					Pop_stackOprd(&oprd);//��ջ

					double L = Top_stackOprd(&oprd);
					Pop_stackOprd(&oprd);
					//����
					double res = Calculate(Top_stackOprt(&oprt), L, R);
					Pop_stackOprt(&oprt);//����������
					//��������ջ
					Push_stackOprd(&oprd, res);
				}
			}
			else if (*p == ')')
			{
				//ͬ��������˼·��ֻ���ж�������һ��
				while (Top_stackOprt(&oprt) != '(')
				{
					double R = Top_stackOprd(&oprd);//��ʽ�ұ���ջ��
					Pop_stackOprd(&oprd);//��ջ

					double L = Top_stackOprd(&oprd);
					Pop_stackOprd(&oprd);
					//����
					double res = Calculate(Top_stackOprt(&oprt), L, R);
					Pop_stackOprt(&oprt);//����������
					//��������ջ
					Push_stackOprd(&oprd, res);
				}
				Pop_stackOprd(&oprd);
			}
		}
		else if (*p == ' ')
			;//�������������ʼ���
		p++;//ֱ�ӷŵ�ĩβ
	}
	printf("�����%lf\n", Top_stackOprd(&oprd));
}

int main()
{
	//Run_test();
	//printf("%d\n", 0 % 2);
	//printf("%d\n", 9 % -5);
	//printf("%d\n", 9 % 3.2);
	GetAns();

	return 0;
}

