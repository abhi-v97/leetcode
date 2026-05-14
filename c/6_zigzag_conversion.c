#include <stdlib.h>
#include <string.h>

/**
 * We need to convert the string "PAYPALISHIRING" into the following
 * pattern:
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * then return the output as "PAHNAPLSIIGYIR"
 *
 * this can be calculated with mathematical expressions instead of
 * creating a matrix
 * the top and bottom rows can be calculated with numRows * 2 - 2
 * the middle rows alternate between going up and down
 */
char *convert(char *s, int numRows)
{
	char *result;
	int	  i;
	int	  j;
	int	  k;
	int	  len;
	int	  step;
	int	  up;

	i = -1;
	k = 0;
	step = (numRows - 1) * 2;
	if (step <= 0)
		step = 1;
	len = strlen(s);
	result = malloc(sizeof(char) * (len + 1));
	while (++i < numRows)
	{
		j = i;
		up = 1; // tracks whether we're going up or down in the zigzag pattern
		while (j < len)
		{
			result[k++] = s[j];
			if (i == 0 || i == (numRows - 1)) // check for top or bottorm row
				j += step;
			else if (up)
			{
				j += step - (i * 2);
				up = 0;
			}
			else
			{
				j += (i * 2);
				up = 1;
			}
		}
	}
	result[k] = '\0';
	return (result);
}

#include <stdio.h>

int main()
{
	printf("s = %s\n", convert("PAYPALISHIRING", 3));
}

