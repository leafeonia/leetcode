class Solution:
    def longestPalindrome(self, s: str) -> str:
        ans = ""
        le = -1
        for i in range(len(s)):
            for j in range(0,len(s)):
                left = i - j
                right = i + j
                if left < 0 or right >= len(s):
                    break
                if s[left] != s[right]:
                    break
                if right - left + 1 > le:
                    le = right - left + 1
                    ans = s[left:right+1]
        for i in range(len(s)-1):
            if s[i] != s[i+1]:
                continue
            for j in range(0,len(s)):
                left = i - j
                right = i + 1 + j
                if left < 0 or right >= len(s):
                    break
                if s[left] != s[right]:
                    break
                if right - left + 1 > le:
                    le = right - left + 1
                    ans = s[left:right+1]
        return ans

