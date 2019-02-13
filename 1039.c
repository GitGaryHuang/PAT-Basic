/*
1039 到底买不买 （20 分）
小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。
输入格式：

每个输入包含 1 个测试用例。每个测试用例分别在 2 行中先后给出摊主的珠串和小红想做的珠串，两串都不超过 1000 个珠子。

输出格式：

如果可以买，则在一行中输出 Yes 以及有多少多余的珠子；如果不可以买，则在一行中输出 No 以及缺了多少珠子。其间以 1 个空格分隔。
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char ccommodity[10000], cdemand[10000];//字符串形式保存手链

	int icommodity[1000], idemand[1000];//数组形式保存手链，不同下标代表不同颜色。0-61 分别代表 0-9 A-Z a-z
	memset(icommodity, 0, sizeof(icommodity));
	memset(idemand, 0, sizeof(idemand));

	gets(ccommodity);
	gets(cdemand);

	for(int i = 0; i < strlen(ccommodity); i++)//将老板卖的链子的形式由字符串形式保存为数组形式。
		if(ccommodity[i] >= '0' && ccommodity[i] <= '9')
			icommodity[ccommodity[i] - 48]++;
		else if(ccommodity[i] >= 'A' && ccommodity[i] <= 'Z')
			icommodity[ccommodity[i] - 55]++;
		else if(ccommodity[i] >= 'a' && ccommodity[i] <= 'z')
			icommodity[ccommodity[i] - 61]++;

	for(int i = 0; i < strlen(cdemand); i++)//将所需要的链子的形式由字符串形式保存为数组形式。
		if(cdemand[i] >= '0' && cdemand[i] <= '9')
			idemand[cdemand[i] - 48]++;
		else if(cdemand[i] >= 'A' && cdemand[i] <= 'Z')
			idemand[cdemand[i] - 55]++;
		else if(cdemand[i] >= 'a' && cdemand[i] <= 'z')
			idemand[cdemand[i] - 61]++;

	int flag = 1;//flag标记表明是否满足 判断条件为商品链子所含有的各种颜色的珠子的个数均大于需求。
	for(int i = 0; i < 62; i++)
	{
		if(idemand[i] > icommodity[i])
		{
			flag = 0;
			break;
		}
	}

	if(flag == 1)//若满足，则多的珠子个数即商品链子的珠子个数-需求链子的珠子个数。
	{
		int more = strlen(ccommodity) - strlen(cdemand);
		printf("Yes %d", more);
	}
	else//不满足，则需求的珠子个数即所有缺少的颜色的珠子的个数之和。
	{
		int less = 0;
		for(int i = 0; i < 62; i++)
			if(idemand[i] > icommodity[i])
				less += idemand[i] - icommodity[i];
		printf("No %d", less);
	}
}