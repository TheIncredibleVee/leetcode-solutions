class Solution:
    def countAsterisks(self, s: str) -> int:
        arr = s.split('|')
        res = 0
        i = 0
        for str in arr:
            i += 1
            if i % 2 == 0:
                continue
            for c in str:
                if c == '*':
                    res += 1
        return res