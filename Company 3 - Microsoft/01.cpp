Que-
Given an integer array arr of size N, the task is to divide it into two sets S1 and S2 such that the absolute difference between their sums is minimum and find the minimum difference.



// standard DP Problem
// subset sum problem

class Solution{

  public:
  
    int fun(int i, int cur, int &sum, int n, int *arr, vector<vector<int>> &dp) {
        if(i >= n){
            int ans = abs((2 * cur) - sum);
            return ans;
        }
        if(dp[i][cur] != -1) return dp[i][cur];
        
        int fr = fun(i+1, cur + arr[i], sum, n, arr, dp);
        int sc = fun(i+1, cur, sum, n, arr, dp);
        
        int ans = min(fr, sc);
        
        return dp[i][cur] = ans;
        
    }
  
	int minDifference(int arr[], int n)  { 
	    int sum = 0;
	    for(int i = 0; i < n; i++) {
	        sum += arr[i];
	    }
	    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
	    
	    int ans = fun(0, 0, sum, n, arr, dp);
	    return ans;
	} 
};