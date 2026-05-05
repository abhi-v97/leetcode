#include <iostream>
#include <string>
#include <unordered_map>

/**
 *  for each string character, update the last index it was seen and max length
 *  of the longest substring currently found.
 *
 */
class Solution
{
public:
	int lengthOfLongestSubstring(std::string s)
	{
		int							  maxLength = 0;
		int							  start = 0;
		std::unordered_map<char, int> lastSeen;

		for (int end = 0; end < s.length(); end++)
		{
			char c = s[end];
			if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= start)
				start = lastSeen[c] + 1;
			maxLength = std::max(maxLength, end - start + 1);
			lastSeen[c] = end;
		}
		return maxLength;
	}
};

int main()
{
	Solution sol;

	std::cout << sol.lengthOfLongestSubstring("abcabcbb") << std::endl;
}
