/*
1067 ������ ��20 ��)
������ͼ��¼ĳ��ϵͳȴ��������ʱ��ϵͳһ��ֻ�������㳢�����޶�Σ��������������ʱ���˺žͻᱻ���������������ʵ�����С���ܡ�

�����ʽ��

�����ڵ�һ�и���һ�����루���Ȳ����� 20 �ġ��������ո�Tab���س��ķǿ��ַ�������һ�������� N���� 10�����ֱ�����ȷ�������ϵͳ�����ԵĴ��������ÿ�и���һ���Իس������ķǿ��ַ��������û�������������롣���뱣֤������һ�γ��ԡ�������һ��ֻ�е��� # �ַ�ʱ�����������������һ�в����û������롣

�����ʽ��

���û���ÿ�����룬�������ȷ�������ҳ��Դ��������� N������һ������� Welcome in����������������Ǵ���ģ�����һ���а���ʽ��� Wrong password: �û�����Ĵ������룻�������Դﵽ N ��ʱ�������һ��  Account locked������������
*/
//���ѵ㣬�����û���������ո�������getline�������cin
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string password, inpassword;
	int N;
	cin >> password >> N;
	getchar();

	while (N > 0)
	{
		getline(cin, inpassword);
		if (inpassword.compare("#") == 0)
			break;
		else if (password.compare(inpassword) == 0)
		{
			cout << "Welcome in" << endl;
			break;
		} 
		else
		{
			cout << "Wrong password: " << inpassword << endl;
			if (--N == 0)
				cout << "Account locked";
		}
	}

	return 0;
}