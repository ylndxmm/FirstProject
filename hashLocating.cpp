#include<stdio.h>
#include<string.h>
struct student
{
	char name[3000];
};
struct student s[30];
int hash(char* cp)//哈希查找
{
	int sum = 0;
	char* p;
	p = cp;
	int n = strlen(cp);
	for (int i = 0; i < n; i++)
	{
		sum += (*p);
		p++;
	}
	while (sum < 0)
		sum = sum + 30;
	int k = sum % 30;
	while (s[k].name[0] != '\0' && strcmp(s[k].name, cp) != 0)
	{
		k = (k + 1) % 30;
	}
	if (s[k].name[0] != '\0')
	{
		printf("该学生在表格中第%d位\n",k+1);
	}
	else
		printf("错误\n");
	return 0;
}
void hash_save()
{
	int i = 0, n = 3;
	char name[3000];
	char* p;
	while (n--)
	{
		int sum = 0;
		printf("输入学生姓名：");
		scanf_s("%s",name,3000);
		p = name;
		int k = strlen(name);
		for (i = 0; i < k; i++)
		{
			sum += (int)*p;
			p++;
		}
		while (sum < 0)
		{
			sum = sum + 30;
		}
		int index = sum % 30;
		while (s[index].name[0] != '\0')
		{
			index = (index + 1) % 30;
		}
		int x = 0;
		while (name[x] != '\0')
		{
			s[index].name[x] = name[x];
			x++;
		}
	}
}
void main()
{
	hash_save();
	char name[30];
	printf("输入需要查找的学生姓名:");
	scanf_s("%s", name,300);
	hash(name);
	printf("输入需要查找的学生姓名:");
	scanf_s("%s", name,300);
	hash(name);
}