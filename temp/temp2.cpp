#include<stdio.h>
int main()
{
	int a[10];
	int min, max;
	double ave = 0, sum = 0;
	//输入
	for (int i = 0;i < 10;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	//求和
	for (int i = 0;i < 10;i++) {
		sum = sum + a[i];
	}
	printf("%lf\n", sum);
	printf("ave=%lf\n",sum/10 );
	max = a[0];
	min = a[0];
	for (int i = 0;i < 10;i++)
	{
		if (max < a[i]) max = a[i];
		if (min > a[i]) min = a[i];
	}
	printf("%d  %d", max, min);

	return 0;
}
