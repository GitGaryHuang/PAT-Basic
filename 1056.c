/*
1056 组合数的和 （15 分）
给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。

输入格式：

输入在第一行中给出 N（1 < N < 10），随后一行给出 N 个不同的非 0 个位数字。数字间以空格分隔。

输出格式：

输出所有可能组合出来的2位数字的和。
*/
//无难点
#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	double sum = 0;
	scanf("%d", &n);
	int number[n];
	for(int i = 0; i < n; i++)
		scanf("%d", &number[i]);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
		{
			if(i != j)
				sum += number[i] * 10 + number[j];
		}
			

	printf("%.0lf", sum);

	return 0;
}