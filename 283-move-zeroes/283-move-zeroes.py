class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        ptr1=0
        ptr2=0
        while ptr2<len(nums):
            if(nums[ptr2]!=0):
                temp= nums[ptr1]
                nums[ptr1] = nums[ptr2]
                nums[ptr2]= temp
                ptr1+=1
            ptr2+=1
        """
        Do not return anything, modify nums in-place instead.
        """
        