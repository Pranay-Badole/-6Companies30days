Que-

// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.

class Solution {
  public:
    
    
    bool canPair(vector<int> v, int k) {
        
        int n = v.size();
        int cnt[k];
        memset(cnt, 0, sizeof cnt);
        
        for(int i = 0; i < n; i++) {
            cnt[v[i] % k]++;    
        }
        
        if(cnt[0] & 1) return 0;
        
        for(int i = 1; i < k; i++){
            int l = i, r = k - i;
            if(l > r) break;   
            if(l == r){
                if(cnt[l] & 1) return 0;
            }
            else{
                if(cnt[l] != cnt[r]){
                     return 0;
                }
            }
        }
        return 1;
    }
};