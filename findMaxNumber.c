#include<stdio.h>
int findmax(int a[], int n)
{
	int max = 0, i;
	for (i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}
int main()
{
	int N = 10;
	int a[] = {3,8,7,6,5,4,3,2,1,0 };
	int max = findmax(a, N);
	printf("%d", max);
	return 0;

}
