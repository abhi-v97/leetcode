from typing import List

"""
    traverse array at each element, calculate difference between target value
    and current value. If the value is in the hashmap, we've got our answer. If
    not, add it to the hashmap.
"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}

        for i in range(len(nums)):
            temp = target - nums[i]
            if temp in hashmap:
                return [hashmap[temp], i]
            hashmap[nums[i]] = i
        return []


if __name__ == "__main__":
    sol = Solution()

    result = sol.twoSum([1, 3, 34, 7, 11, 23], 18)
    print(result)
