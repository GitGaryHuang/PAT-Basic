/*
1030 完美数列 （25 分）
给定一个正整数数列，和正整数 p，设这个数列中的最大值是 M，最小值是 m，如果 M≤mp，则称这个数列是完美数列。

现在给定参数 p 和一些正整数，请你从中选择尽可能多的数构成一个完美数列。

输入格式：

输入第一行给出两个正整数 N 和 p，其中 N（≤10
​5
​​ ）是输入的正整数的个数，p（≤10
​9
​​ ）是给定的参数。第二行给出 N 个正整数，每个数不超过 10
​9
​​ 。

输出格式：

在一行中输出最多可以选择多少个数可以用它们组成一个完美数列。
*/
//难点：用double型表示更大范围的数 、判断时方法重要以避免超时：外循环i从n-1开始递减 内循环j从i-max开始递减，判断mp是否小于M(这种方式比较次数最少)
//参考https://github.com/xiaoqiang179/PAT_Basic/blob/master/1030.c
#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b);

int main()
{
	int n, i, j;
	double p, q[100000];
	scanf("%d %lf", &n, &p);
	int max = 0;
	for(int i = 0; i < n; i++)
		scanf("%lf", &q[i]);
	qsort(q, n, sizeof(double), cmp);//升序排序

	for(i = n - 1; i >= max; i--)
	{
		for(j = i - max; j >= 0; j--)
		{
			if(q[i] > p * q[j])
			{
				max = i - j;
				break;
			}
		}
		if(i - j > max)
			max = i - j;
	}
	printf("%d", max);

	return 0;
}

int cmp(const void *a, const void *b)
{
	return *(double *)a - *(double *)b;
}