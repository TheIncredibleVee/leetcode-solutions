class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows=len(matrix)
        cols=len(matrix[0])
        low=0
        high=rows-1
        reqrow=-1
        while high>=low:
            mid=(low+high)//2
            if matrix[mid][cols-1]==target:
                return True
            if matrix[mid][cols-1]>target:
                reqrow=mid
                high=mid-1
            else:
                low=mid+1
        low=0
        high=cols-1
        while high>=low:
            mid=(high+low)//2
            if matrix[reqrow][mid]==target:
                return True
            if matrix[reqrow][mid]>target:
                high=mid-1
            else:
                low=mid+1
        return False