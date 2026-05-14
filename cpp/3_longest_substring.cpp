#include <string>
#include <unordered_map>

class Solution
{
	int lengthOfLongestSubstring(std::string s)
	{
		int							  maxLength = 0;
		int							  start = 0;
		std::unordered_map<char, int> index;

		for (int end = 0; end < s.length(); end++)
		{

			if (index.find(s[end]) != index.end() && index[s[end]] >= start)
				start = index[s[end]] + 1;
			maxLength = std::max(maxLength, end - start + 1);
			index[s[end]] = end;
		}
		return maxLength;
	}
};
