#include <iostream>
#include <string>

class Solution
{
public:
	std::string convert(std::string s, int numRows)
	{
		std::string result("");

		int step = (numRows - 1) * 2;
		if (step <= 0)
			step = 1;

		for (int i = 0; i < numRows; i++)
		{
			int up = 1;
			for (int j = i; j < s.length();)
			{
				result += s[j];
				if (i == 0 || i == numRows - 1)
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
		return (result);
	}
};

int main()
{
	Solution sol;

	std::cout << sol.convert("PAYPALISHIRING", 4) << std::endl;
}
