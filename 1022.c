/*
1022 D进制的A+B （20 分）
输入两个非负 10 进制整数 A 和 B (≤2
​30
​​ −1)，输出 A+B 的 D (1<D≤10)进制数。

输入格式：

输入在一行中依次给出 3 个整数 A、B 和 D。

输出格式：

输出 A+B 的 D 进制数。
*/

#include<stdio.h>

int main()
{
	//输入a、b、d三个数，c为ab的和，若和为0，输出0，若不为0，进行进制转换并输出。
	int a, b, c;
	int d;
	int result[32];
	scanf("%d %d %d", &a, &b, &d);
	c = a + b;
	if(c == 0)
	{
		printf("0");
		return 0;
	}

	int i = 0;

	while(c != 0)
	{
		result[i] = c % d;
		c /= d;
		i++;
	}

	for(int n = i - 1; n >= 0; n--)
		printf("%d", result[n]);

	return 0;
}