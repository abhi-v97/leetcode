#include "stdlib.h"
#include "string.h"

/**
 * Simple algorithm, goes through each index in string and tries to find the biggest possible
 * palindrome.
 */
char *longestPalindrome(char *s)
{
	char *ptr = s;
	char *substr = s;
	char *start;
	char *end;
	int	  max_len = 1;

	if (*s == '\0')
		return ("");
	while (*ptr)
	{
		start = ptr;
		end = ptr;

		while (*(end + 1) && *(end + 1) == *end)
			end++;
		ptr = end + 1;
		while (*(end + 1) && (start > s) && *(end + 1) == *(start - 1))
		{
			start--;
			end++;
		}
		if (end - start + 1 > max_len)
		{
			max_len = end - start + 1;
			substr = start;
		}
	}
	char *result = (char *) calloc((max_len + 1), sizeof(char));
	strncpy(result, substr, max_len);
	return (result);
}

