/*
1027 打印沙漏 （20 分）
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****
所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:

输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:

首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
*/

#include<stdio.h>

int main()
{
	int n;
	char sym;
	scanf("%d %c", &n, &sym);
	//沙漏中符号的个数n满足公式n=2*i^2-1（其中阶数i=1，2，3…… 对应沙漏层数height为1，3，5，即2*i-1，该值也是底层与顶层的符号个数……）
	int i = 1;
	while(n >= 2 * (i + 1) * (i + 1) - 1)
		i++;
	int bottom = 2 * i - 1;
	int unused = n - ((bottom + 1) * (bottom + 1) / 2 - 1);
	//printf("%d %d %d", n, i, bottom);
	for(int j = i; j >= 1; j--)//输出倒三角
	{
		for(int k = i - j; k > 0; k--)
			printf(" ");
		for(int l = 0; l < 2 * j - 1; l++)
			printf("%c", sym);
		printf("\n");
	}
	for(int j = 2; j <= i; j++)//输出正三角
	{
		for(int k = i - j; k > 0; k--)
			printf(" ");
		for(int l = 0; l < 2 * j - 1; l++)
			printf("%c", sym);
		printf("\n");
	}
	printf("%d", unused);

	return 0;
}