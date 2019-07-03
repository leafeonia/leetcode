class Solution:
    # dp[i][j]表示[i,j]区间内的字符构成回文串
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        max_len = 0
        dp = [([0]*1000) for i in range(1000)]
        for r in range(len(s)):
            for l in range(r+1):
                if s[l] == s[r] and (r - l < 3 or dp[l+1][r-1]):
                    dp[l][r] = True
                    if r - l + 1 > max_len:
                        max_len = r - l + 1
                        ans = s[l:r+1]
                else:
                    dp[l][r] = False
        return ans