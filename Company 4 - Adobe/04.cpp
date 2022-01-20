**Partition Equal Subset Sum**

Que - Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.


STANDARD DP PROBLEM


class Solution{
public:    
    
    bool fun(int i, int sum, int arr[], int n, vector<vector<bool>> &dp) {
        if(sum == 0) return 1;
        if(sum < 0 || i >= n) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        
        bool ans = 0;
        ans = ans | fun(i+1, sum - arr[i], arr, n, dp);
        ans = ans | fun(i+1, sum, arr, n, dp);
        
        return (dp[i][sum] = ans);
        
    }

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i = 0; i < N; i++){
            sum += arr[i];
        }
        if(sum & 1) return 0;
        sum /= 2;
        
        vector<vector<bool>> dp(N+1, vector<bool>(sum+1, -1));
        int ans = fun(0, sum, arr, N, dp);
        return ans;
    }
};
