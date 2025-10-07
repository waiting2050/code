//ц╟ещеепР 
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;
	scanf("%d", &num);

	int* arr = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - 1 - i; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}

	free(arr);

		return 0;
}
