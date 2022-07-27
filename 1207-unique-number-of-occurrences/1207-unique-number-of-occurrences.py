class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        dic={}
        for i in arr:
            if i in dic:
                dic[i]+=1
            else:
                dic[i]=1
        s=set()
        for i in dic.values():
            if i in s:
                return False
            else:
                s.add(i)
        return True
        