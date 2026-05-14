#include <string>

class Solution
{
public:
	std::string longestPalindrome(std::string s)
	{
		if (s.empty())
			return ("");

		size_t bestStart = 0;
		size_t bestLen = 0;

		for (size_t i = 0; i < s.size();)
		{
			size_t start = i;
			size_t end = i;

			while (end + 1 < s.size() && s[end + 1] == s[end])
				end++;
			i = end + 1;

			while (end + 1 < s.size() && start > 0 && s[end + 1] == s[start - 1])
			{
				start--;
				end++;
			}

			if (end - start + 1 > bestLen)
			{
				bestLen = end - start + 1;
				bestStart = start;
			}
		}

		return s.substr(bestStart, bestLen);
	}
};

#include <iostream>

int main()
{
	Solution sol;

	std::cout << sol.longestPalindrome("xaabacxcabaaxcabaax") << std::endl;
}
