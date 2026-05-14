class Solution:
    def convert(self, s: str, numRows: int) -> str:
        result = ""

        step = (numRows - 1) * 2
        if step <= 0:
            step = 1

        i = 0
        while i < numRows:
            up = 1
            j = i
            while j < len(s):
                result += s[j]
                if i == 0 or i == numRows - 1:
                    j += step
                elif up:
                    j += step - (i * 2)
                    up = 0
                else:
                    j += (i * 2)
                    up = 1
            i += 1
        return result


if __name__ == "__main__":
    sol = Solution()

    print(sol.convert("PAYPALISHIRING", 4))
