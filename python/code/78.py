class Solution:
    def subsets(self, nums):
        res = [[]]
        for i in nums:
            res = res + [[i] + num for num in res]
        return res

        ret = []
        for i in range(2 ** len(nums)):
            element = []
            cnt = 0
            while i > 0:
                if i & 1 == 1:
                    element.append(nums[cnt])
                cnt += 1
                i >>= 1
            ret.append(element)
        return ret
