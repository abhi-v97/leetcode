class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_length = 0
        start = 0
        last_seen = {}

        for end, c in enumerate(s):
            if c in last_seen and last_seen[c] >= start:
                start = last_seen[c] + 1

            max_length = max(max_length, end - start + 1)
            last_seen[c] = end

        return max_length


if __name__ == "__main__":
    sol = Solution()

    print(sol.lengthOfLongestSubstring("abcabcbb"))
