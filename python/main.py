class Solution:
    def reverse(self, x: int) -> int:

        if x < 0:
            sign = -1
        else:
            sign = 1
        ans =  sign * int(str(abs(x))[::-1])
        if ans >= -2**31 and ans < 2**31:
            return ans
        else:
            return 0

sol = Solution()
print(Solution.reverse(sol,1534236469))
