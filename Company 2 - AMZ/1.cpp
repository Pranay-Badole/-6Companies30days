Que -

// In the stock market, a person buys a stock and sells it on some future date. Given the stock prices of N days in an array A[ ] 
// and a positive integer K, find out the maximum profit a person can make in at-most K transactions. 
// A transaction is equivalent to (buying + selling) of a stock and new transaction can start only when the previous transaction has been completed.



class Solution {
  public:
    
    int dp[505][205][2];
    
    // i -> current day
    // K -> no of transactions left
    // -> have == 1 : the stock is already bought we need to sell
    // -> have == 0 : the stock isn't bought we need to buy

    int fun(int i, int K, int N, int *A, int have) {
        if(i >= N) {
            if(have) return INT_MIN;
            else return 0;
        }
        // cout << i << ' ';
        if(K <= 0) return 0;
        if(dp[i][K][have] != -1) return dp[i][K][have];
        
        int ans = 0;
        
        if(!have) {
            // buying current stock
            int fr = fun(i+1, K, N, A, (1-have));
            // will cause error(INT_MIN - A[i]) can go in positive and hence wrong ans
            if(fr != INT_MIN) fr -= A[i]; 
            
            // skipping current stock
            int sc = fun(i+1, K, N, A, have);
            
            ans = max(fr, sc);
        }
        else {
            // selling current stock
            int fr = fun(i+1, K-1, N, A, (1-have));
            if(fr != INT_MIN) fr += A[i];
            
            // skipping current stock
            int sc = fun(i+1, K, N, A, have);
            ans = max(fr, sc);
        }
        
        
        return dp[i][K][have] = ans;
    }
  
    int maxProfit(int K, int N, int A[]) {
        memset(dp, -1, sizeof dp);
        int ans = fun(0, K, N, A, 0);
        return ans;
    }
};