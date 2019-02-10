/*
1012 数字分类 （20 分）
给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：

A
​1
​​  = 能被 5 整除的数字中所有偶数的和；
A
​2
​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n
​1
​​ −n
​2
​​ +n
​3
​​ −n
​4
​​ ⋯；
A
​3
​​  = 被 5 除后余 2 的数字的个数；
A
​4
​​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
A
​5
​​  = 被 5 除后余 4 的数字中最大数字。
输入格式：

每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的 N 个正整数，按题目要求计算 A
​1
​​ ~A
​5
​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出 N。
*/

#include<stdio.h>

int main()
{
	int n, temp;
	int A1 = 0, A2 = 0, A3 = 0,A5 = -10001;
	double A4 = 0;
	int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &temp);
		if(temp % 10 == 0)
		{
			A1 += temp;
			a1++;
		}
		else if(temp % 5 == 1 && a2 % 2 == 0)
		{
			A2 += temp;
			a2++;
		}
		else if(temp % 5 == 1 && a2 % 2 == 1)
		{
			A2 -= temp;
			a2++;
		}
		else if(temp % 5 == 2)
		{
			A3++;
			a3++;
		}
		else if(temp % 5 == 3)
		{
			A4 += temp;
			a4++;
		}
		else if(temp % 5 ==4)
		{
			if(temp > A5)
				A5 = temp;
			a5++;
		}
	}
	if(a1 == 0)
		printf("N ");
	else 
		printf("%d ", A1);
	if(a2 == 0)
		printf("N ");
	else 
		printf("%d ", A2);
	if(a3 == 0)
		printf("N ");
	else 
		printf("%d ", A3);
	if(a4 == 0)
		printf("N ");
	else 
		printf("%.1f ", A4 / a4);
	if(a5 == 0)
		printf("N");
	else 
		printf("%d", A5);

	return 0;

}