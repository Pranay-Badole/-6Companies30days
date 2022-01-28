**Stone Game**

Que-

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row.
 This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.



Solution-
This problem was repeated in some prev companys problem (there it was asked to find the max stones alice can get).

NICE game theory and DP.

class Solution {
public:
    
    int fun(int l, int r, vector<int> &piles, vector<vector<int>> &dp) {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int fr = piles[l] + min(fun(l+1, r-1, piles, dp), fun(l+2, r, piles, dp));
        int sc = piles[r] + min(fun(l, r-2, piles, dp), fun(l+1, r-1, piles, dp));
        
        int ans = max(fr, sc);
        
        return dp[l][r] = ans;
        
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        
        int sum = 0;
        for(auto &x : piles) sum += x;
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        int ans = fun(0, n-1, piles, dp);
        // cout << ans << ' '  << sum << endl;
        return (ans > sum/2);
    }
};