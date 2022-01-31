**Maximum Performance of a Team**

Que-
You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.

Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

The performance of a team is the sum of their engineers speeds multiplied by the minimum efficiency among their engineers.

Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.


Solution-
I did without heap,
again try to think and approach backwards.

Here I traversed efficiency in increasing order, so was a little complex
but if i would have tried backwards(in decreasing order) then it was an easy min heap approach.


class Solution {
public:
    const int M = 1e9 + 7;
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        
        vector<vector<int>> v;
        vector<vector<int>> sp;
        
        for(int i = 0; i < n; i++) {
            v.push_back({e[i], s[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < n; i++) {
            sp.push_back({v[i][1], i});
        }
        sort(sp.begin(), sp.end(), [](vector<int> a, vector<int> b){return a[0] > b[0];});
        
        
        int j = 0;
        int cnt = 0;
        long long sum = 0;
        k--;
        unordered_set<int> st;
        long long ans = 0;
        
        for(int i = 0; i < n; i++) {
            long long mul = v[i][0];
            if(st.count(i)){
                sum = (sum - v[i][1]);
                cnt--;
                st.erase(i);
            }
            
            while(j < n && cnt < k) {
                if(sp[j][1] <= i){j++;continue;}
                sum = (sum + sp[j][0]);
                st.insert(sp[j][1]);
                cnt++;
                j++;
            }
            // cout << i << ' ' << sum << endl;
            long long temp = (mul * (sum + v[i][1]));
            
            ans = max(ans, temp);
            
        }
        return ans%M;
    }
                           
};