/*
1016 部分A+B （15 分）
A B为两个整数 DA DB为两个1位整数。
求A中DA的个数，如A=3694246, DA=6，则A中有2个A，得到数字66。
最终求DA+DB。
*/
#include<stdio.h>

int main()
{
	long A, B;
	int DA, DB;
	int countA = 0, countB = 0;
	scanf("%ld %d %ld %d", &A, &DA, &B, &DB);//格式化输入
	long AResult = 0, BResult = 0, Result = 0;

	while(A  != 0)//计数
	{
		if(A % 10 == DA)
			countA++;
		A /= 10;
	}

	while(B != 0)
	{
		if(B % 10 == DB)
			countB++;
		B /= 10;
	}

	for(int i = 0; i < countA; i++)//计算
	{
		AResult = AResult * 10 + DA;
	}

	for(int i = 0; i < countB; i++)
	{
		BResult = BResult * 10 + DB;
	}

	Result = AResult + BResult;//求和

	printf("%ld", Result);//输出

	return 0;
}