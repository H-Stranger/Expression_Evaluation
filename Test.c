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
void Run_test()
{
	////创建操作符和操作数结构体
	//StackOprt oprt;
	//StackOprd oprd;
	//Init_stackOprt(&oprt);
	//Init_stackOprd(&oprd);
	//printf("%d\n", Init_stackOprd(&oprt));
	////入栈测试
	//printf("%d\n", Push_stackOprt(&oprt, 'c'));
	//printf("%d\n", Push_stackOprt(&oprt, 'd'));
	//printf("%d\n", Push_stackOprt(&oprt, 'e'));

	////出栈测试
	//printf("%d\n", Pop_stackOprt(&oprt));

	//printf("%c\n", Top_stackOprt(&oprt));//栈顶测试
	//printf("%d\n", Pop_stackOprt(&oprt));

	//printf("%c\n", oprt.oprt[oprt.top - 1]);

	//printf("%d\n", Pop_stackOprt(&oprt));
	//printf("%d\n", Pop_stackOprt(&oprt));//栈空
	//printf("%d\n", isEmpty_stackOprt(&oprt));//判断栈空测试


	//printf("--------------------------------\n");

	////测试符号优先级
	//printf("%d\n",Prior('+'));
	////操作符
	//printf("%d\n",Is_oprt(')'));

	////计算函数测试
	//printf("%f\n", Calculate('+', 2, 3));
	//printf("%lf\n", Calculate('^', 2, 4));
	////printf("%lf\n", Calculate('/', 2, 0));
	//printf("提示：小数取余会直接被进行整数处理\n");
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

	char* p = str;//通过数组地址处理
	int num = 0;//操作数整型
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
			num = 0;
			int res = Push_stackOprd(&oprd, num);
			//p++;
		}
		else if (Is_oprt(*p))
		{
			//优先级：栈顶元素优小于字符串操作符
			if (*p == '(' || Prior(Top_stackOprt(&oprt)) < Prior(*p))
			{
				Push_stackOprt(&oprt, *p);
				
				//栈顶元素和字符串都为#结束
				if (Top_stackOprt(&oprt) == '#' && *p == '#')
					return Top_stackOprd(&oprd);//最终计算的结果
			}
			else if (Prior(&oprt) >= Prior(*p))
			{
				//当前操作符栈里的所有元素都弹出直到#
				while (Top_stackOprd(&oprt) != '#')
				{
					double R = Top_stackOprd(&oprd);//等式右边在栈顶
					Pop_stackOprd(&oprd);//出栈

					double L = Top_stackOprd(&oprd);
					Pop_stackOprd(&oprd);
					//计算
					double res = Calculate(Top_stackOprt(&oprt), L, R);
					Pop_stackOprt(&oprt);//操作符弹出
					//计算结果入栈
					Push_stackOprd(&oprd, res);
				}
			}
			else if (*p == ')')
			{
				//同样的运算思路，只是判断条件不一样
				while (Top_stackOprt(&oprt) != '(')
				{
					double R = Top_stackOprd(&oprd);//等式右边在栈顶
					Pop_stackOprd(&oprd);//出栈

					double L = Top_stackOprd(&oprd);
					Pop_stackOprd(&oprd);
					//计算
					double res = Calculate(Top_stackOprt(&oprt), L, R);
					Pop_stackOprt(&oprt);//操作符弹出
					//计算结果入栈
					Push_stackOprd(&oprd, res);
				}
				Pop_stackOprd(&oprd);
			}
		}
		else if (*p == ' ')
			;//数组向后继续访问即可
		p++;//直接放到末尾
	}
	printf("结果：%lf\n", Top_stackOprd(&oprd));
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

