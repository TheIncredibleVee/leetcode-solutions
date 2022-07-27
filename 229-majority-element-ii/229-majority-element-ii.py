class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # dic={}
        # n=len(nums)
        # if n==1:
        #     return nums
        # for i in nums:
        #     if i not in dic:
        #         dic[i]=1
        #     else:
        #         dic[i]+=1
        # res=[]
        # for i in dic.keys():
        #     if dic[i]>(n//3):
        #         res.append(i)
        # return res
        res=[]
        n=len(nums)
        if n==1:
            return nums
        elem1=elem2=0
        cnt1=cnt2=0
        for idx, val in enumerate(nums):
            if elem1==val:
                cnt1+=1
            elif elem2==val:
                cnt2+=1
            elif cnt1==0:
                elem1=val
                cnt1+=1
            elif cnt2==0:
                elem2=val
                cnt2+=1
            else:
                cnt1-=1
                cnt2-=1
        cnt1=cnt2=0
        for i in nums:
            if i==elem1:
                cnt1+=1
            elif i==elem2:
                cnt2+=1
        if cnt1>(n//3):
            res.append(elem1)
        if cnt2>(n//3):
            res.append(elem2)
        return res
            
            