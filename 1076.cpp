/*
1076 Wifi密码 （15 分)
下面是微博上流传的一张照片：“各位亲爱的同学们，鉴于大家有时需要使用 wifi，又怕耽误亲们的学习，现将 wifi 密码设置为下列数学题答案：A-1；B-2；C-3；D-4；请同学们自己作答，每两日一换。谢谢合作！！~”—— 老师们为了促进学生学习也是拼了…… 本题就要求你写程序把一系列题目的答案按照卷子上给出的对应关系翻译成 wifi 的密码。这里简单假设每道选择题都有 4 个选项，有且只有 1 个正确答案。
*/
//无难点
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	getchar();
	string s;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < 4; j++)
		{
			cin >> s;
			if (s[2] == 'T')
				cout << s[0] - 'A' + 1;
		}

	return 0;
}