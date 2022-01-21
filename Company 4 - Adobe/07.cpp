**Pots of Gold Game**
GOOD QUESTION

Two players X and Y are playing a game in which there are pots of gold arranged in a line, each containing some gold coins. 
They get alternating turns in which the player can pick a pot from one of the ends of the line. The winner is the player who has a higher number of coins at the end. 
The objective is to maximize the number of coins collected by X, assuming Y also plays optimally.

Return the maximum coins X could get while playing the game. Initially, X starts the game.


SOLUTION

Let the list be v = {8 15 3 7}
l = 0, r = 3

as we start the game we have 2 choices
    :choose start index 'l' (fr - the total coins we get selecting 'l')
    :choose end index 'r' (sc - the total coins we get selecting 'r')

    as we want to maximize the no of coins so we will choose the maximum of both 
    ans = max(fr, sc);

    case 1: selecting 'l'
        the remaining v will be {15, 3, 7} (l + 1 -> r)
        now its opponents turn so he will choose the index which will give us the minimum coins
        that is; either {15, 3} or {3, 7}
        
        fr = v[l] + min((l+2 -> r), (l+1 -> r-1));

    case 2: selecting 'r'
        similarly here
        the remaining v will be {8 15 3} (l -> r - 1)

        sc = v[r] + min((l+1 -> r-1), (l -> r-2));

    Just we have to recurse this logic while (l <= r) and memoize it

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

class Solution {
public:

    int fun(int l, int r, vector<int> &v, vector<vector<int>> &dp) {
        
        if(l > r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        int fr = v[l] + min(fun(l+1, r-1, v, dp), fun(l+2, r, v, dp));
        int sc = v[r] + min(fun(l, r-2, v, dp), fun(l+1, r-1, v, dp));
        
        int ans = max(fr, sc);
        return dp[l][r] = ans;
    }
    
    int maxCoins(vector<int> &v, int n)
    {   
        vector<vector<int>> dp(n, vector<int>(n, -1));
	    int ans = fun(0, n-1, v, dp);
	    return ans;
    }
};