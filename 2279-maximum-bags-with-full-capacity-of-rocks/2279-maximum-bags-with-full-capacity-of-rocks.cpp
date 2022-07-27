class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int i=0;
        int res=0;
        for(auto &x: capacity){
            x -= rocks[i++];
        }
        sort(capacity.begin(), capacity.end());
        i=0;
        while(i < capacity.size() && additionalRocks >= capacity[i] ){
            additionalRocks -= capacity[i];
            i++;
        }
        return i;
    }
};