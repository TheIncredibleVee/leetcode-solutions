# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> int:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low= 1
        res=-1;
        high=n
        while low<=high:
            mid=int(low+(high-low)/2)
            if isBadVersion(mid)!=0:
                res=mid
                high=mid-1
            else:
                low=mid+1
        return res
        