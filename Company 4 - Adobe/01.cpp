Que-
Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.


Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}

Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12


class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int v[], int n, long long s)
    {
        int l = 0, r = 0;
        long long sum = 0;
        vector<int> ans = {};
        
        for(l = 0; l < n; l++) {
            r = max(r, l);
            while(r < n && sum < s){
                sum += v[r++];
            }
            if(sum == s) {
                ans.push_back(l+1);
                ans.push_back(r);
                return ans;
            }
            sum -= v[l];
        }
        ans.push_back(-1);
        return ans;
    }
};