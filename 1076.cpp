/*
1076 Wifi���� ��15 ��)
������΢����������һ����Ƭ������λ�װ���ͬѧ�ǣ����ڴ����ʱ��Ҫʹ�� wifi�����µ������ǵ�ѧϰ���ֽ� wifi ��������Ϊ������ѧ��𰸣�A-1��B-2��C-3��D-4����ͬѧ���Լ�����ÿ����һ����лл��������~������ ��ʦ��Ϊ�˴ٽ�ѧ��ѧϰҲ��ƴ�ˡ��� �����Ҫ����д�����һϵ����Ŀ�Ĵ𰸰��վ����ϸ����Ķ�Ӧ��ϵ����� wifi �����롣����򵥼���ÿ��ѡ���ⶼ�� 4 ��ѡ�����ֻ�� 1 ����ȷ�𰸡�
*/
//���ѵ�
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