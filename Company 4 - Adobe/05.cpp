**Express as sum of power of natural numbers**

Que - Given two numbers n and x, find out the total number of ways n can be expressed as sum of xth power of unique natural numbers.
As total number of ways can be very large ,so return the number of ways modulo 1e9 + 7. 

class Solution{
    int M = 1e9 + 7;
    public:
    
    long long power(int a, int b){
        if(b == 0) return 1;
        
        long long t = power(a, b/2);
        t = (t * t) % M;
        if(b & 1) t = (t * a) % M;
        
        return t;
    }
    int dp[1002][1002];
    
    int fun(int i, int sum, int &x, int &n) {
        if(sum == n) return 1;
        if(sum > n || i > n) return 0;
        
        if(dp[i][sum] != -1) return dp[i][sum];
        int t = power(i, x);
        
        int ans = 0;
        ans = (fun(i+1, sum, x, n) + fun(i+1, sum + t, x, n)) % M;
        
        return dp[i][sum] = ans;
    }
    
    int numOfWays(int n, int x)
    {   
        memset(dp, -1, sizeof dp);
        int ans;
        ans = fun(1, 0, x, n);
        return ans;
    }
};