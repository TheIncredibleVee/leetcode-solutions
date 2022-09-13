class Solution {
// private:
//     int find_msb(int n){
//         n = n | (n >> 1);
//         n = n | (n >> 2);
//         n = n | (n >> 4);
//         n = n | (n >> 8);
//         n = n | (n >> 16);
//         n= (n + 1) >> 1 | (n & (1 << ((sizeof(n) * CHAR_BIT)-1)));
//         return log2(n);
//     }
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i = 0; i< n; ++i){
            int byte_size = 0;
            int temp = data[i];
            while( byte_size < 8 && temp & (1<<(7 - byte_size))){
                byte_size++;
            }
            if(byte_size == 1 || byte_size > 4){
                return false;
            }
            if(!byte_size){
                continue;
            }
            cout<<i<<" "<<byte_size<<endl;
            while(--byte_size){
                i++;
                if( i >= n){
                    return false;
                }
                int next_val = data[i];
                if(!(next_val & (1<<7)) || (next_val & (1<<(7-1)))){
                    return false;
                }
            }
        }
        return true;
    }
};