/*
1013 数素数 （20 分）
令 P
​i
​​  表示第 i 个素数。现任给两个正整数 M≤N≤10
​4
​​ ，请输出 P
​M
​​  到 P
​N
​​  的所有素数。

输入格式：

输入在一行中给出 M 和 N，其间以空格分隔。

输出格式：

输出从 P
​M
​​  到 P
​N
​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
*/

#include<stdio.h>
#include<math.h>

int IsPrime(int a);

int main()
{
	int a[10001];
	int j, k;
	scanf("%d %d", &j, &k);
	int n = 0;
	for(int i = 2; n <= 10000; i++)
	{
		if(IsPrime(i))
		{
			n++;
			a[n] = i;
		}
	}
	int count = 1;
	for(int i = j; i <= k; i++)
	{

		printf("%d", a[i]);
		if(count < k - j + 1 && count % 10 != 0)
			printf(" ");
		else if(count % 10 == 0 && count < k - j + 1)
			printf("\n");
		count++;		
	}
	return 0;
	

}

int IsPrime(int a)
{
	if(a <= 1)
		return 0;
	int root = sqrt(a);
	for(int i = 2; i <= root; i++)
		if(a % i == 0)
			return 0;

	return 1;
}