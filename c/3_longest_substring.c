#include <string.h>

int lengthOfLongestSubstring(char *s)
{
	int n = strlen(s);
	int maxLength = 0;
	int start = 0;
	int charIndex[256]; // ASCII character set

	for (int i = 0; i < 256; i++)
	{
		charIndex[i] = -1; // Initialize all indices to -1
	}

	for (int end = 0; end < n; end++)
	{
		if (charIndex[(unsigned char) s[end]] >= start)
		{
			start = charIndex[(unsigned char) s[end]] + 1;
		}
		charIndex[(unsigned char) s[end]] = end;
		maxLength = (maxLength > (end - start + 1)) ? maxLength : (end - start + 1);
	}

	return maxLength;
}
