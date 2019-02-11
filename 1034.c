/*
1034 有理数四则运算 （20 分）
本题要求编写程序，计算 2 个有理数的和、差、积、商。

输入格式：

输入在一行中按照 a1/b1 a2/b2 的格式给出两个分数形式的有理数，其中分子和分母全是整型范围内的整数，负号只可能出现在分子前，分母不为 0。

输出格式：

分别在 4 行中按照 有理数1 运算符 有理数2 = 结果 的格式顺序输出 2 个有理数的和、差、积、商。注意输出的每个有理数必须是该有理数的最简形式 k a/b，其中 k 是整数部分，a/b 是最简分数部分；若为负数，则须加括号；若除法分母为 0，则输出 Inf。题目保证正确的输出中没有超过整型范围的整数。

输入样例 1：
*/

#include<stdio.h>

long GCD(long a, long b);//求最大公约数
void PrintFraction(long a, long b, long flag);//打印分式,flag为1、2、3、4分别表示加减乘除运算，为0表示普通格式化输出。

int main()
{
	long a1, a2, b1, b2;

	scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

	PrintFraction(a1, b1, 0);
	printf("+ ");
	PrintFraction(a2, b2, 0);
	printf("= ");
	PrintFraction(a1 * b2 + a2 * b1, b1 * b2, 1);//输出加法结果
	PrintFraction(a1, b1, 0);
	printf("- ");
	PrintFraction(a2, b2, 0);
	printf("= ");
	PrintFraction(a1 * b2 - a2 * b1, b1 * b2, 2);//输出减法结果

	PrintFraction(a1, b1, 0);
	printf("* ");
	PrintFraction(a2, b2, 0);
	printf("= ");
	PrintFraction(a1 * a2, b1 * b2, 3);//输出乘法结果

	PrintFraction(a1, b1, 0);
	printf("/ ");
	PrintFraction(a2, b2, 0);
	printf("= ");
	if(a1 > 0 && a2 < 0)//为避免a2为负数，影响与b1相乘后的格式错误情况。
	{
		a1 = -a1;
		a2 = -a2;
	}
	else if(a1 < 0 && a2 < 0)
	{
		a1 = -a1;
		a2 = -a2;
	}
	PrintFraction(a1 * b2, a2 * b1, 4);//输出除法结果
}

long GCD(long a, long b)
{
	long c = a % b;
	return c == 0 ? (b > 0 ? b : -b) : GCD(b, c);
}

void PrintFraction(long a, long b, long flag)
{
	if(flag == 0)//等号左边格式化输出
	{
		if(a == 0)//若a为0，输出0
		{
			printf("0 ");
		}
		else if(a / b == 0)//若a/b为0，即|a|<|b|，直接化简输出。
		{
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld/%ld ", a, b);
			else if(a < 0)
				printf("(%ld/%ld) ", a, b);
		}
		else if(a % b == 0)//a能被b整除，输出a/b的结果。
		{
			long c = a / b;
			if(a > 0)
				printf("%ld ", c);
			else 
				printf("(%ld) ", c);
		}
		else//a/b不为0且a%b不为0
		{
			long c = a / b;
			a %= b;
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld %ld/%ld ", c, a, b);
			else
				printf("(%ld %ld/%ld) ", c, -a, b);//-a 使(-8/3) -> (-2 -2/3)这种错误情况变成(-2 2/3)，即作用于正确的格式输出。
		}
	}
	else if(flag == 1 || flag == 2 || flag == 3)//等号右边加减乘的格式化输出（flag的设立主要便于区分不同运算，实际只需要对除法进行区分即可。）
	{
		if(a == 0)
		{
			printf("0\n");
		}
		else if(a / b == 0)
		{
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld/%ld\n", a, b);
			else if(a < 0)
				printf("(%ld/%ld)\n", a, b);
		}
		else if(a % b == 0)
		{
			long c = a / b;
			if(a > 0)
				printf("%ld\n", c);
			else 
				printf("(%ld)\n", c);
		}
		else
		{
			long c = a / b;
			a %= b;
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld %ld/%ld\n", c, a, b);
			else
				printf("(%ld %ld/%ld)\n", c, -a, b);
		}
	}
	else if(flag == 4)//由于除数为0需要特殊处理因此除法的格式化输出需要做修改。
	{
		if(b == 0)
			printf("Inf");
		else if(a == 0)
		{
			printf("0");
		}
		else if(a / b == 0)
		{
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld/%ld", a, b);
			else if(a < 0)
				printf("(%ld/%ld)", a, b);
		}
		else if(a % b == 0)
		{
			long c = a / b;
			if(a > 0)
				printf("%ld", c);
			else 
				printf("(%ld)", c);
		}
		else
		{
			long c = a / b;
			a %= b;
			long d = GCD(a, b);
			a /= d;
			b /= d;
			if(a > 0)
				printf("%ld %ld/%ld", c, a, b);
			else
				printf("(%ld %ld/%ld)", c, -a, b);
		}
	}
	

}