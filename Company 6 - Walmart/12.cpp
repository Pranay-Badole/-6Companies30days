**Find Array Given Subset Sums**

Que-
You are given an integer n representing the length of an unknown array that you are trying to recover. 
You are also given an array sums containing the values of all 2n subset sums of the unknown array (in no particular order).

Return the array ans of length n representing the unknown array. If multiple answers exist, return any of them.

An array sub is a subset of an array arr if sub can be obtained from arr by deleting some (possibly zero or all) elements of arr. 
The sum of the elements in sub is one possible subset sum of arr. The sum of an empty array is considered to be 0.



class Solution {
public:
     
    vector<int> recoverArray(int n, vector<int>& sums) {
        vector<int> ans;
        sort(sums.begin(), sums.end());
        
        while(n--) {
            int ele = sums[1] - sums[0];
            
            multiset<int> st(sums.begin(), sums.end());
            
            vector<int> nt1;
            vector<int> nt2;
            
            int fr = 0;
            int j = 0;
            
            for(int i = 0; i < sums.size(); i++) {
                if(sums[i] != INT_MAX){
                    if(sums[i] == 0) fr = 1;
                    j = max(j+1, i+1);
                    
                    for(j; j < sums.size(); j++) {
                        if(sums[i] + ele == sums[j]) break;
                    }
                    nt1.push_back(sums[i]);
                    nt2.push_back(sums[j]);
                    
                    sums[j] = INT_MAX;
                }
            }
            if(fr){
                ans.push_back(ele);
                sums = nt1;
            }
            else{
                ans.push_back(-ele);
                sums = nt2;
            }
        }
        return ans;
    }
};