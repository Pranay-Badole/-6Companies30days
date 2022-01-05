Que -

// Given an array of positive integers nums and a positive integer target, return the minimal length of a contiguous subarray [numsl, numsl+1, ..., numsr-1, numsr] of which the sum is greater than or equal to target. If there is no such subarray, return 0 instead.


#define ll      long long

class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int n = v.size();
        int l = 0;
        int r = 0;
        int ans = INT_MAX;
        ll sum = 0;        
        
        while(1) {
            // cout << l << ' ' << r << ' ' << sum << endl;
            if(sum < t) {
                if(r == n) break;
                sum += v[r];
                r++;
            }
            else{
                ans = min(ans, r - l);
                sum -= v[l];
                l++;
            }
        }
        return (ans == INT_MAX ? 0 : ans);
    }
};