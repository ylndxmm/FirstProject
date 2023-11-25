#include<stdio.h>
int main()
{
	int  m,n;
	scanf_s("%d", &m);
	if (m > 3)
	{
		for (n = 2; n < m; n++)
		{
			if (m % n == 0)
				break;
		}
		if (m <= n)
			printf("yes ");
		else printf("no");
	}
	else printf("error");
	return 0;
}