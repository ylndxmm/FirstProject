#include<stdio.h>
#include<string.h>
struct student
{
	char name[3000];
};
struct student s[30];
int hash(char* cp)//��ϣ����
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
		printf("��ѧ���ڱ���е�%dλ\n",k+1);
	}
	else
		printf("����\n");
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
		printf("����ѧ��������");
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
	printf("������Ҫ���ҵ�ѧ������:");
	scanf_s("%s", name,300);
	hash(name);
	printf("������Ҫ���ҵ�ѧ������:");
	scanf_s("%s", name,300);
	hash(name);
}