/*
1018 锤子剪刀布 （20 分）
大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：

FigCJB.jpg

现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第 1 行给出正整数 N（≤10
​5
​​ ），即双方交锋的次数。随后 N 行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C 代表“锤子”、J 代表“剪刀”、B 代表“布”，第 1 个字母代表甲方，第 2 个代表乙方，中间有 1 个空格。

输出格式：

输出第 1、2 行分别给出甲、乙的胜、平、负次数，数字间以 1 个空格分隔。第 3 行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有 1 个空格。如果解不唯一，则输出按字母序最小的解
*/
//无难点。
#include<stdio.h>

int main()
{
	static int n;
	scanf("%d", &n);
	getchar();
	char P[3];
	int result[2][6] = {0};//保存比赛结果 
	for(int i = 0; i < n; i++)
	{
		//printf("第%d回合\n", i+1);
		gets(P);
		if(P[0] == 'B' && P[2] == 'C') //p1:布 p2:锤
		{
			result[0][0]++;
			result[1][2]++;
			result[0][3]++;
		}
		else if(P[0] == 'B' && P[2] =='J')//p1:布 p2:剪
		{
			result[0][2]++;
			result[1][0]++;
			result[1][4]++;
		}
		else if(P[0] == P[2])//相同
		{
			result[0][1]++;
			result[1][1]++;
		}
		else if(P[0] == 'J' && P[2] =='B')//p1:剪 p2:布
		{
			result[0][0]++;
			result[1][2]++;
			result[0][4]++;
		}
		else if(P[0] == 'J' && P[2] =='C')//p1:剪 p2:锤
		{
			result[0][2]++;
			result[1][0]++;
			result[1][5]++;

		}
		else if(P[0] == 'C' && P[2] =='B')//p1:锤 p2:布
		{
			result[0][2]++;
			result[1][0]++;
			result[1][3]++;
		}
		else if(P[0] == 'C' && P[2] =='J')//p1:锤 p2:剪
		{
			result[0][0]++;
			result[1][2]++;
			result[0][5]++;
		}
		//printf("%d %d %d", result[0][0], result[0][1], result[0][2]);
	}

	for(int i = 0; i < 3; i++)
		printf("%d%c", result[0][i], i == 2 ? '\n' : ' ');
	for(int i = 0; i < 3; i++)
		printf("%d%c", result[1][i], i == 2 ? '\n' : ' ');

	char p1max = 'B';
	char p2max = 'B';
	if(result[0][3] >= result[0][5] && result[0][3] >= result[0][4])
		p1max = 'B';
	else if(result[0][5] >= result[0][4] && result[0][5] > result[0][3])
		p1max = 'C';
	else 
		p1max = 'J';
	if(result[1][3] >= result[1][5] && result[1][3] >= result[1][4])
		p2max = 'B';
	else if(result[1][5] >= result[1][4] && result[1][5] > result[1][3])
		p2max = 'C';
	else 
		p2max = 'J';
	printf("%c %c", p1max, p2max);

	return 0;
}