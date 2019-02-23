/*
1037 在霍格沃茨找零钱 （20 分）
如果你是哈利·波特迷，你会知道魔法世界有它自己的货币系统 —— 就如海格告诉哈利的：“十七个银西可(Sickle)兑一个加隆(Galleon)，二十九个纳特(Knut)兑一个西可，很容易。”现在，给定哈利应付的价钱 P 和他实付的钱 A，你的任务是写一个程序来计算他应该被找的零钱。

输入格式：

输入在 1 行中分别给出 P 和 A，格式为 Galleon.Sickle.Knut，其间用 1 个空格分隔。这里 Galleon 是 [0, 10
​7
​​ ] 区间内的整数，Sickle 是 [0, 17) 区间内的整数，Knut 是 [0, 29) 区间内的整数。

输出格式：

在一行中用与输入同样的格式输出哈利应该被找的零钱。如果他没带够钱，那么输出的应该是负数。
*/
//无难点
#include<stdio.h>

int main()
{
	int aG, aS, aK;
	int bG, bS, bK;
	int rG, rS, rK;
	int result, a, b;
	scanf("%d.%d.%d %d.%d.%d", &aG, &aS, &aK, &bG, &bS, &bK);

	a = aG * 17 * 29 + aS * 29 + aK;
	b = bG * 17 * 29 + bS * 29 + bK;

	result = a > b ? a - b : b - a;

	rG = result / 29 / 17;
	rS = result / 29 % 17;
	rK = result % 29;
 	if(a > b)
		printf("-%d.%d.%d", rG, rS, rK);
	else
		printf("%d.%d.%d", rG, rS, rK);
}