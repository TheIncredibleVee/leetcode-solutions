class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        neg=-1
        pos=-1
        res = []
        for i in range(0, len(nums)):
            if nums[i]>=0:
                pos=i
                neg=i-1
                break
        if pos==0:
            for i in range (0,len(nums)):
                res.append(nums[i]*nums[i])
            return res
        if pos==-1:
            for i in range (0,len(nums)):
                res.append(nums[len(nums)-1-i]*nums[len(nums)-1-i])
            return res
        while neg>=0 and pos<len(nums):
            if(nums[pos]<abs(nums[neg])):
                res.append(nums[pos]*nums[pos])
                pos+=1
            else:
                res.append(nums[neg]*nums[neg])
                neg-=1
        while pos<len(nums):
            res.append(nums[pos]*nums[pos])
            pos+=1
        while neg>=0:
            res.append(nums[neg]*nums[neg])
            neg-=1
        return res
            