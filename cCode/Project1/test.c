#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{

	int arr[] = { 0 };
	int i;
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		printf("%d", arr[i]);
	}

	return 0;
}