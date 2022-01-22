**Minimum operations to convert array A to B**


Given two Arrays A[] and B[] of length N and M respectively. Find the minimum number of insertions and deletions on the array A[], required to make both the arrays identical.
Note: Array B[] is sorted and all its elements are distinct, operations can be performed at any index not necessarily at end.

// VERY NICE QUESTION
// learnt that we can calculate LIS in O(NlogN) as well using "patience sorting" (patience is the key XD)

// also here it was crucial that B[] is sorted and it contains all unique elements

class Solution {
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        
        vector<int> v;
        unordered_set<int> st;
        
        for(int i = 0; i < m; i++) st.insert(b[i]);
        
        for(int i = 0; i < n; i++) {
            if(st.count(a[i])) v.push_back(a[i]);    
        }
        
        vector<int> lis = {};
        
        for(int i = 0; i < v.size(); i++) {
        int idx = lower_bound(lis.begin(), lis.end(), v[i]) - lis.begin();
        
            if(idx >= lis.size()) lis.push_back(v[i]);
            else lis[idx] = v[i];
        } 
        // for(auto &x : lis) cout << x << ' ';
        
        return n + m - 2*(lis).size();
    }
};