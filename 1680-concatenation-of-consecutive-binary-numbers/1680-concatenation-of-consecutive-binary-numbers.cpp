class Solution {
public:
    int bits(int n) {
		  return log2(n) + 1;
    }
    
    int concatenatedBinary(int n) {
        long res = 0, MOD = 1e9 + 7;
        
        for (int i = 1; i <= n; ++i) {
            int len = bits(i);
            res = ((res << len) % MOD + i) % MOD;
        }
        return res;
    }
};