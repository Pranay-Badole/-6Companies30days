**Sorted subsequence of size 3**

Que-
Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k.


Solution-


We can view the problem as for every element (j)
    :find if it has a element (i) on its left which is less than j
    :find if it has a element (k) on its right which is greater than j

if an element satisfies this
return {i, j, k};

Alternate solution - LIS with path (yet to learn) (N*logN).

class Solution{
  public:
    vector<int> find3Numbers(vector<int> v, int n) {
        
        vector<int> ans;
        if(n < 3) return ans;
        
        vector<int> prev(n);
        int mn = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(mn < v[i]){
                prev[i] = mn;
            }
            else{
                prev[i] = -1;
            }
            mn = min(mn, v[i]);
        }
        int mx = -1;
        
        for(int i = n-1; i >= 0; i--) {
            if(mx > v[i]){
                if(prev[i] != -1) {
                    ans = {prev[i], v[i], mx};  
                    return ans;
                }
            }
            mx = max(mx, v[i]);
        }
        return ans;
    }
};