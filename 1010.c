/*
1010 一元多项式求导 （25 分）
设计函数求一元多项式的导数。（注：x
​n
​​ （n为整数）的一阶导数为nx
​n−1
​​ 。）

输入格式:

以指数递降方式输入多项式非零项系数和指数（绝对值均为不超过 1000 的整数）。数字间以空格分隔。

输出格式:

以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。注意“零多项式”的指数和系数都是 0，但是表示为 0 0
*/

#include<stdio.h>

int main()
{
	int a[1000], b[1000];//两个数组保存每次系数和指数
	int n = 0;
	for(int i = 0; i < 1000; i++, n++)//格式化输入
	{
		scanf("%d %d", &a[i], &b[i]);
		if(b[i] == 0)
			break;
	}
	for(int j = 0; j <= n; j++)//格式化输出
	{
		if(a[j] == 0 || b[j] == 0)
			printf("0 0\n");
		else 
		{
			printf("%d %d", a[j] * b[j], b[j] - 1);
			if(j == n - 1)
			{
				printf("\n");
				break;
			}
			else 
				printf(" ");
		}

	}
}