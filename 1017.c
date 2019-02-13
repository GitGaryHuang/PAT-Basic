#include<stdio.h>
#include<string.h>

int main()
{
	char cnumber[1005];
	gets(cnumber);
	int n = strlen(cnumber);//n保存字符串长度 n-2为整数的长度。
	int inumber[1005];//inumber以数组形式保存整数。
	int rnumber[1005];//rnumber保存商
	
	for(int i = 0; cnumber[i] != ' '; i++)//
	{
			inumber[i] = cnumber[i] - 48;
	}

	int p = cnumber[n-1] - 48;//p为除数
	n = n - 2;//整数数组长度

	//if(n == 1)
	int dividend = 0;
	int rem = 0;//rem保存余数
	for(int i = 0; i < n; i++)
	{
		dividend = rem * 10 + inumber[i];
		rnumber[i] = dividend / p;
		rem = dividend % p;
	}
	for(int i = 0; i < n ; i++)
	{
		if(i == 0 && rnumber[i] ==0)
			continue;
		else
			printf("%d", rnumber[i]);
	}
	printf(" %d", rem);


}