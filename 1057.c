/*
给定一串长度不超过 10
​5
​​  的字符串，本题要求你将其中所有英文字母的序号（字母 a-z 对应序号 1-26，不分大小写）相加，得到整数 N，然后再分析一下 N 的二进制表示中有多少 0、多少 1。例如给定字符串 PAT (Basic)，其字母序号之和为：16+1+20+2+1+19+9+3=71，而 71 的二进制是 1000111，即有 3 个 0、4 个 1
*/
//无难点
#include<stdio.h>
#include<string.h>

int main()
{
	char s[100005];//字符串形式读入英文
	int b[100000];
	gets(s);
	int n = strlen(s);
	int sum = 0;
	int count = 0;
	int zero = 0, one = 0;

	for(int i = 0; i < n; i++)//根据ascii码来计算英文的值。
		if(s[i] >= 'A' && s[i] <= 'Z')
			sum += s[i] - 64;
		else if(s[i] >= 'a' && s[i] <= 'z')
			sum += s[i] - 96;

	//10转2进制 数组保存。
	while(sum >= 2)
	{
		b[count++] = sum % 2;
		sum /= 2;
	}
	if(sum == 1)
		b[count++] = 1;
	for(int i = 0; i < count; i++)
		if(b[i] == 0)
			zero++;
		else if(b[i] == 1)
			one++;

	printf("%d %d", zero, one);

	return 0;


}