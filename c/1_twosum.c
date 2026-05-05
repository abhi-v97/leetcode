#include <stdio.h>
#include <stdlib.h>

/**
 * simple brute force approach, loop through each element to see if there is another value equal to
 * target - x
 *
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
	int	 i = 0;
	int	 j = 0;
	int *result;

	while (i < numsSize)
	{
		while (j < numsSize)
		{
			if ((nums[i] + nums[j]) == target && i != j)
			{
				result = malloc(sizeof(int) * 2);
				*returnSize = 2;
				result[0] = i;
				result[1] = j;
				return (result);
			}
			j++;
		}
		j = i + 1;
		i++;
	}
	*returnSize = 0;
	return (NULL);
}

int main()
{
	int	 array_size = 0;
	int	 array[4] = {2, 7, 11, 15};
	int *result = NULL;

	result = twoSum(array, 5, 9, &array_size);
	for (int i = 0; i < array_size; i++)
	{
		printf("%i ", result[i]);
	}
	printf("\n");
	return (0);
}
