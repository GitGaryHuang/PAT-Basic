/*
1009 说反话 （20 分）
给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

输入格式：

测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

输出格式：

每个测试用例的输出占一行，输出倒序后的句子。
*/
#include<stdio.h>
#include<string.h>

int main()
{
	char sentence[10000];//一维数组保存字符串
	char word[100][100];//二维数组保存字符串中的每个单词。
	int block = 0;//空格数，单词数为空格数+1
	int count = 0;//单词数计数器
	gets(sentence);
	int n = strlen(sentence);//字符串长度
	for(int i = 0; i < n; i++)
		if(sentence[i] == ' ')
			block++;
	int k = 0;//计数器，用于保存每个单词时
	for(int i = 0; i < n; i++)
	{
		if(sentence[i] != ' ')
		{
			word[count][k] = sentence[i];
			k++;
		}
		else
		{
			count++;
			k = 0;
		}
	}
	for(int i = block; i >= 0; i--)
		printf("%s%s", word[i], (i ? " " : ""));
}