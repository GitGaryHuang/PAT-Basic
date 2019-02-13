/*
1040 有几个PAT （25 分）
字符串 APPAPT 中包含了两个单词 PAT，其中第一个 PAT 是第 2 位(P)，第 4 位(A)，第 6 位(T)；第二个 PAT 是第 3 位(P)，第 4 位(A)，第 6 位(T)。

现给定字符串，问一共可以形成多少个 PAT？

输入格式：

输入只有一行，包含一个字符串，长度不超过10
​5
​​ ，只包含 P、A、T 三种字母。

输出格式：

在一行中输出给定字符串中包含多少个 PAT。由于结果可能比较大，只输出对 1000000007 取余数的结果。
*/
//代码无难点，思路在于得出如何计算PAT个数：字符串中每个A对应的PAT个数 = 该A前的P个数 * 该A后的T个数，最后对所有的A得到的PAT个数进行累加即可。
#include<stdio.h>
#include<string.h>

int main()
{
	char pat[100050];//字符串
	gets(pat);
	int n = strlen(pat);//n保存pat字符串长度
	int p = 0, t = 0;//p t 计数
	int result[3][100050] = {0};//初始化数组，result[0] [1] [2] 分别保存每个A得到的PAT数， 该A前的P数， 该A后的T数。其中result[0] = result[1] * result[2]
	int sum = 0;//pat计数
	//循环计数，记录每个A前的P个数
	for(int i = 0; i < n; i++)
	{
		if(pat[i] == 'P')
			p++;
		else if(pat[i] == 'A')
			result[1][i] = p;
	}
	//循环计数，记录每个A后的T个数
	for(int i = n - 1; i > 0; i--)
	{
		if(pat[i] == 'T')
			t++;
		else if(pat[i] == 'A')
			result[2][i] = t;
	}
	//计算，每个A能够得到的PAT个数 = 该A前的P个数 * 该A后的T个数。
	for(int i = 0; i < n; i++)
	{
		result[0][i] = result[1][i] * result[2][i];
		sum += result[0][i];
		if(sum >= 1000000007)
			sum %= 1000000007;
	}

	printf("%d", sum);

	return 0;

}