//¶ş·Ö²éÕÒ 
#include <stdio.h>

int main()
{
	int arr[11], target, left = 0, right = sizeof(arr) / sizeof(arr[0]) - 1;
	;
	for (int i = 0; i < 11; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &target);


	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (arr[mid] < target)
		{
			left = mid + 1;
		}
		else if(arr[mid]>target)
		{
			right = mid - 1;
		}
		else
		{
			printf("Find:%d. It is a[%d].", target, mid);
			return 0;
		}
	}

	printf("No such number");

	return 0;
}
