Que-
Given an array nums which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays.

Write an algorithm to minimize the largest sum among these m subarrays.

 

Example 1:

Input: nums = [7,2,5,10,8], m = 2
Output: 18

Explanation:
There are four ways to split nums into two subarrays. The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.


Solution-
Standard "Binary Search on answer" concept problem.
same question as "allocating books" problem.


class Solution {
public:
    
    bool check(int x, vector<int> &v, int &m) {
        int cur = 0;
        int cnt = 1;
        
        for(int i = 0; i < v.size(); i++) {
            if(cur + v[i] > x) {
                cnt++;   
                cur = 0;
            }
            cur += v[i];
        }
        return (cnt <= m);
    }
    
    int splitArray(vector<int>& v, int m) {
        int l = 0, r = 0;
        for(int i = 0; i < v.size(); i++) {
            l = max(l, v[i]);
            r += v[i];
        }
        int ans;
        // cout << l << ' ' << r << endl;
        while(l <= r){
            int mid = l + (r - l)/2;
            if(check(mid, v, m)) {
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return ans;
    }
};