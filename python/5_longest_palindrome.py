class Solution:
    def longestPalindrome(self, s: str) -> str:
        str_len = len(s)
        if (str_len == 0):
            return ("")

        bestStart = 0
        bestLen = 0
        bestStr = s[0]

        for i in range(str_len):
            start = i
            end = i

            while (end + 1 < str_len and s[end + 1] == s[end]):
                end = end + 1
            i = end + 1

            while end + 1 < str_len and start > 0 and s[end + 1] == s[start - 1]:
                start = start - 1
                end = end + 1

            if end - start + 1 > bestLen:
                bestLen = end - start + 1
                bestStart = start
                bestStr = s[bestStart:end + 1]

        return bestStr


if __name__ == "__main__":
    sol = Solution

    print(sol.longestPalindrome("bccd", "bccccd"))
