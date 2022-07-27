class Solution:
    def reverseWords(self, s: str) -> str:
        start=0
        end=0
        res=''
        lst= s.split(' ')
        for idx,i in enumerate(lst):
            res+=i[::-1]
            if idx!=len(lst)-1:
                res+=' '
        return res
                