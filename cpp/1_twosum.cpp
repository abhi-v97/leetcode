#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int> &nums, int target)
	{
		std::unordered_map<int, int> hash;

		for (int i = 0; i < nums.size(); i++)
		{
			int temp = target - nums[i];

			if (hash.find(temp) != hash.end())
				return {hash[temp], i};
			hash[nums[i]] = i;
		}
		return {};
	}
};

int main()
{
	Solution sol;

	std::vector<int> array = {2, 7, 11, 15};
	std::vector<int> result = sol.twoSum(array, 9);
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";
	std::cout << std::endl;
	return (0);
}
