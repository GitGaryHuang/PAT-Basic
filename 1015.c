/*1515德才论
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第一行给出 3 个正整数，分别为：N（≤10^​5​​ ），即考生总数；L（≥60），为录取最低分数线，即德分和才分均不低于 L 的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于 H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线 L 的考生也按总分排序，但排在第三类考生之后。

随后 N 行，每行给出一位考生的信息，包括：准考证号 德分 才分，其中准考证号为 8 位整数，德才分为区间 [0, 100] 内的整数。数字间以空格分隔。

输出格式：

输出第一行首先给出达到最低分数线的考生人数 M，随后 M 行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。
对给定的学生成绩信息进行处理，输出相应的结果。

*/
#include<stdio.h>
#include<stdlib.h>

typedef struct Student//
{
	int id;
	int mgrade;//德分
	int tgrade;//才分
	int wgrade;//德才总分（wgrade = mgrade + tgrade）
}Student;

int cmp(const void *a, const void *b);//比较函数，用于qsort排序
int cmp(const void *a, const void *b)//优先级：总分、德分、学号（若总分、德分相同，学号小优先）
{
	struct Student *s1 = (Student *)a;
	struct Student *s2 = (Student *)b;
	if(s1 -> wgrade != s2 -> wgrade)
		return s1 -> wgrade > s2 -> wgrade ? -1 : 1;
	else if(s1 -> mgrade != s2 -> mgrade)
		return s1 -> mgrade > s2 -> mgrade ? -1 : 1;
	else
		return s1 -> id < s2 -> id ? -1: 1;
}

int main()
{
	int n, l, h;//保存N,L,H；
	scanf("%d %d %d", &n, &l, &h);
	struct Student Astudent[100000], Bstudent[100000], Cstudent[100000], Dstudent[100000];//合格的学生分为ABCD四个档次。
	int id, mgrade, tgrade;
	int a = 0, b = 0, c = 0, d = 0;
	for(int i = 0; i < n; i++)//学生成绩录入并分类
	{
		scanf("%d %d %d", &id, &mgrade, &tgrade);
		if(tgrade >= h && mgrade >= h)
			Astudent[a++] = (struct Student){id, mgrade, tgrade, tgrade + mgrade};
		else if(mgrade >= h && tgrade >= l)
			Bstudent[b++] = (struct Student){id, mgrade, tgrade, tgrade + mgrade};
		else if(mgrade >= l && tgrade >= l && mgrade >= tgrade)
			Cstudent[c++] = (struct Student){id, mgrade, tgrade, tgrade + mgrade};
		else if(mgrade >= l && tgrade >= l)
			Dstudent[d++] = (struct Student){id, mgrade, tgrade, tgrade + mgrade};
	}
	//对各类学生按要求排序并输出。
	qsort(Astudent, a, sizeof(Student), cmp);
	qsort(Bstudent, b, sizeof(Student), cmp);
	qsort(Cstudent, c, sizeof(Student), cmp);
	qsort(Dstudent, d, sizeof(Student), cmp);
	printf("%d\n", a + b + c + d);
	for(int i = 0; i < a; i++)
		printf("%d %d %d\n", Astudent[i].id, Astudent[i].mgrade, Astudent[i].tgrade);
	for(int i = 0; i < b; i++)
		printf("%d %d %d\n", Bstudent[i].id, Bstudent[i].mgrade, Bstudent[i].tgrade);
	for(int i = 0; i < c; i++)
		printf("%d %d %d\n", Cstudent[i].id, Cstudent[i].mgrade, Cstudent[i].tgrade);
	for(int i = 0; i < d; i++)
		printf("%d %d %d\n", Dstudent[i].id, Dstudent[i].mgrade, Dstudent[i].tgrade);

}

