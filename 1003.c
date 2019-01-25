/*
1003 我要通过！ （20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式：

每个测试输入包含 1 个测试用例。第 1 行给出一个正整数 n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过 100，且不包含空格。

输出格式：

每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出 YES，否则输出 NO。
*/


#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	char pat[10][100];
	scanf("%d", &n);//读取行数
	getchar();
	for(int i = 0; i < n; i++)//输入字符串
		gets(pat[i]);
	
	//判断格式
	for(int i = 0; i < n; i++)
	{
		int count[3] = {0, 0, 0};
		int index = 0;
		int j = 0;
		while(j < strlen(pat[i]))
		{
			if(pat[i][j] == 'A')
			{
				count[index]++;
			}
			else if(pat[i][j] == 'P' && index == 0)
				index++;
			else if(pat[i][j] == 'T' && index == 1)
				index++;
			else 
				break;
			j++;
		}

		if(index == 2 && count[1] > 0 && count[2] == count[1] * count[0])
			printf("YES\n");
		else
			printf("NO\n");		
	}

	return 0;

}