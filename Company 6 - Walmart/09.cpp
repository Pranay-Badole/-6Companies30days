**Guess Number Higher or Lower II**

Que-
We are playing the Guessing Game. The game will work as follows:

1. I pick a number between 1 and n.
2. You guess a number.
3. If you guess the right number, you win the game.
4. If you guess the wrong number, then I will tell you whether the number I picked is higher or lower, and you will continue guessing.
5. Every time you guess a wrong number x, you will pay x dollars. If you run out of money, you lose the game.

Given a particular n, return the minimum amount of money you need to guarantee a win regardless of what number I p1ick.


Solution:
In such questions we have to consider that the luck is not in our favour, we should always consider worst case scenario.

out of all the scenarios (considered not in favour) we choose the optimum one.

So basically like in a project estimation- we consider the best out of all the worst and get the estimation.



class Solution {
public:
    
    int fun(int l, int r, vector<vector<int>> &dp) {
        // Base Condition
        // if there is only one element left that's the answer for sure so 0 cost.
        // if there is no element left then no cost.
        if(l >= r) return 0;
        
        // memoize
        if(dp[l][r] != -1) return dp[l][r];
        int ans = INT_MAX;
        
        // considering all scenarios
        for(int k = l; k <= r; k++) {
            int t1 = k + fun(l, k-1, dp);
            int t2 = k + fun(k+1, r, dp);
            
            int temp = max(t1, t2); // considering luck not in our favour

            ans = min(ans, temp); // taking the best out of worst
        }
        
        return dp[l][r] = ans;
    }    
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp (n+1, vector<int>(n+1, -1));
        int ans = fun(1, n, dp);
        return ans;
    } 
};