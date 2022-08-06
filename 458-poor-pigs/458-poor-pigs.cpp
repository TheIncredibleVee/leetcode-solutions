class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int res = 0;
        int t = minutesToTest/minutesToDie + 1;
        while(pow(t,res) < buckets) res++;
        return res;
    }
};