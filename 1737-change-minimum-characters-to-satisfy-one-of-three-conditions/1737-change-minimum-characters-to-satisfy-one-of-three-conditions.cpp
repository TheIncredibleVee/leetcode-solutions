class Solution {
public:
    int minCharacters(string a, string b) {
        int ta[26] = {0}, tb[26] = {0}, na = a.size(), nb = b.size();
    
    for(auto &ch: a) ta[ch - 'a']++;
    for(auto &ch: b) tb[ch - 'a']++;
    
    int sa = INT_MAX, sb = INT_MAX, Ma = ta[25], Mb = tb[25];
    
    for(int i = 0, ma = na, mb = 0; i != 25;  Ma = max(Ma, ta[i++]))
      sa = min(sa , (ma -= ta[i]) + (mb += tb[i]));
      
    for(int i = 0, ma = 0, mb = nb; i != 25;  Mb = max(Mb, tb[i++]))
      sb = min(sb , (ma += ta[i]) + (mb -= tb[i]));
     
    return min( (na - Ma) + (nb - Mb) , min(sa, sb));
    }
};