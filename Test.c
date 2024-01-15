#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"

//计算函数		必须放在主函数里才能正确运算出结果
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
			printf("被除数不为0！\n");
			exit(-1);//程序直接结束运行
		}
		else
			return L / R;
	}
	case '^': return pow(L, R);
	case '%': return (int)L % (int)R;
	default:
	{
		printf("暂不提供“%c”支持!\n", c);
		return 0;
	}

	}
}

//功能：弹出操作数栈的两个数和操作符栈的一个操作符进行运算，并将结果重新入操作数栈
void stackCal(StackOprt* poprt, StackOprd* poprd)
{
	double R = Top_stackOprd(poprd);//等式右边在栈顶
	Pop_stackOprd(poprd);//出栈

	double L = Top_stackOprd(poprd);
	Pop_stackOprd(poprd);
	//计算
	double res = Calculate(Top_stackOprt(poprt), L, R);
	Pop_stackOprt(poprt);//操作符弹出
	//计算结果入栈
	printf("%lf操作数计算结果入栈>\n", res);
	Push_stackOprd(poprd, res);
}

//功能：展示表达式运算过程
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
	//创建结构体 初始化
	StackOprt oprt;
	StackOprd oprd;
	Init_stackOprd(&oprd);
	Init_stackOprt(&oprt);

	printf("请输入表达式:>(以#开头结尾)\n");
	//接收表达式
	char str[MAX_SIZE];
	gets(str);

	char* p = str;//创建指针处理字符数组
	double num = 0;//多个单字符转换多位数
	while (*p != '\0')
	{
		//判断操作数
		if (Is_oprd(*p))
		{
			num = num * 10 + (*p - '0');
			if (Is_oprd(*(p+1)))//如果下一个字符也是操作数
			{
				p++;
				continue;	//数组往后判断，num值保留
			}
			//结果入栈
			Push_stackOprd(&oprd, num);
			num = 0;
		}
		else if (Is_oprt(*p))
		{
			//初始'#'入栈 左括号单独判断入栈
			if (*p == '#' && oprd.top == 0 || *p=='(')
			{
				Push_stackOprt(&oprt, *p);
			}
			else if (*p == ')')
			{
				//同样的运算思路，只是判断条件不一样
				while (Top_stackOprt(&oprt) != '(')
				{
					stackCal(&oprt, &oprd);
				}
				Pop_stackOprt(&oprt);//左括号弹出去
			}
			else if (*p == '#' && oprt.oprt[0] == '#')
			{
				while (Top_stackOprt(&oprt) != '#')
				{
					stackCal(&oprt, &oprd);
				}
			}
			//优先级：栈顶元素优小于字符串操作符
			else if (Prior(Top_stackOprt(&oprt)) < Prior(*p))
			{
				Push_stackOprt(&oprt, *p);
			}
			else if (Prior(Top_stackOprt(&oprt)) >= Prior(*p))
			{
				//当前操作符栈里的所有元素都弹出直到#
				stackCal(&oprt, &oprd);
				Push_stackOprt(&oprt, *p);
			}
		}
		//如果碰到空格判断语句均跳过
		Print(p);
		p++;//直接放到末尾
	}
	printf("运算结果：%lf\n", Top_stackOprd(&oprd));
}


void menu()
{
	printf("*****************************************\n");
	printf("***********    1.表达式求值   ***********\n");
	printf("***********     2.课设创作    ***********\n");
	printf("***********       0.退出      ***********\n");
	printf("*****************************************\n");
}
void ShowInfo()
{
	printf("\n");
	printf("*****************************************\n");
	printf(" >Class: 22级计算机科学与技术专业        \n");
	printf(" >Author:  何秀东   邱鹏                 \n");
	printf(" >Created Time: 2024年1月15日    星期一  \n");
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
			printf("退出\n");
			break;
		}
	} while (input);
	
	return 0;
}
