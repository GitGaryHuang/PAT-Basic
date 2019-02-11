/*
1020 月饼 （25 分）
月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。

注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有 3 种月饼，其库存量分别为 18、15、10 万吨，总售价分别为 75、72、45 亿元。如果市场的最大需求量只有 20 万吨，那么我们最大收益策略应该是卖出全部 15 万吨第 2 种月饼、以及 5 万吨第 3 种月饼，获得 72 + 45/2 = 94.5（亿元）。

输入格式：

每个输入包含一个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N 表示月饼的种类数、以及不超过 500（以万吨为单位）的正整数 D 表示市场最大需求量。随后一行给出 N 个正数表示每种月饼的库存量（以万吨为单位）；最后一行给出 N 个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。

输出格式：

对每组测试用例，在一行中输出最大收益，以亿元为单位并精确到小数点后 2 位。
*/

//apple代表mooncake。。。
#include<stdio.h>
void bubble(int n, double apple[][1001]);

int main()
{
	int n;
	int count = 0;
	double demand;
	double sum = 0;
	scanf("%d %lf", &n, &demand);//苹果种类数、需求

	double apple[3][1001];


	for(int i = 0; i < n; i++)
		scanf("%lf", &apple[0][i]);
	for(int i = 0; i < n; i++)
	{
		scanf("%lf", &apple[1][i]);
		apple[2][i] = apple[1][i] / apple[0][i];
	}

	bubble(n, apple);
	
	while(demand != 0 && count < n)//sum总价累加，demand需求累减直到为0，count计数小于n，防止供给不够情况循序继续往后走。
	{	
		//printf("demand:%.2f\n", demand);
		if(demand >= apple[0][count])
		{
			//printf("demand >= count\n");
			demand -= apple[0][count];
			sum += apple[1][count];
			//printf("demand:%.2f, perprice=%.2f,sum:%.2f\n", demand, apple[2][count],sum);
			count++;
		}
		else if(demand < apple[0][count])
		{
			//printf("demand < count\n");
			sum += demand * apple[2][count];
			demand = 0;
			//printf("demand:%.2f, perprice=%.2f,sum:%.2f\n", demand, apple[2][count],sum);
		}
	}

	//for(int i = 0; i < n; i++)
	//{
	//	printf("%.2f %.2f %.2f\n%.2f", apple[0][i], apple[1][i], apple[2][i], sum);
	//}

	printf("%.2f", sum);


}

//冒泡排序，按单价降序。
void bubble(int n, double apple[][1001])
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n - i -1; j++)
		{
			//printf("%.2f<%.2f\n", apple[2][j], apple[2][j + 1]);
			if(apple[2][j] < apple[2][j + 1])
			{
				double temp0 = apple[0][j];
				apple[0][j] = apple[0][j + 1];
				apple[0][j + 1] = temp0;
				double temp1 = apple[1][j];
				apple[1][j] = apple[1][j + 1];
				apple[1][j + 1] = temp1;
				double temp2 = apple[2][j];
				apple[2][j] = apple[2][j + 1];
				apple[2][j + 1] = temp2;
			}
		}
}

