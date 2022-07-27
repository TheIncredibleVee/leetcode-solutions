class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        res=0
        low=0
        high=len(nums)-1
        while high>=low:
            mid= int(low + (high-low)/2)
            if target == nums[mid]:
                res=mid
                break
            elif target>nums[mid]:
                low=mid+1
                res=mid+1
            else:
                high=mid-1
        return res
        