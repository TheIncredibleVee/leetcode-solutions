class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        lst1 =[0]*26
        lst2= [0]*26
        if(len(s1)>len(s2)):
            return False
        for idx,val in enumerate(s1):
            lst1[ord(s1[idx])-ord('a')]+=1
            lst2[ord(s2[idx])-ord('a')]+=1
        for i in range(0, len(s2)-len(s1)):
            if(self.cmp(lst1,lst2)):
                return True
            lst2[ ord(s2[ i + len(s1) ] ) - ord( 'a' ) ]+=1
            lst2[ord(s2[i])-ord('a')]-=1
        return self.cmp(lst1,lst2)
    def cmp(self, lst1:list, lst2:list)->bool:
        for idx,val in enumerate(lst1):
            if val != lst2[idx]:
                return False
        return True
            
