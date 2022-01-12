Que- Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. 
According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. 
The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. 
He asks for your help to find the maximum money he can get if he strictly follows the rule. Each house has a[i]amount of money present in it.


class Solution
{
    int dp[10005];
    public:
        
    
    int fun(int i, int arr[], int n){
        
        // base case: if we have reached the end no more houses left
        // no house left so no loot i.e '0'
        if(i >= n){
            return 0;
        }
        // check if value is noted already
        if(dp[i] != -1){
            return dp[i];
        }
        // skipping this house and moving to next
        int fr = fun(i+1, arr, n);

        // looting this house ans moving to the house skipping the next one
        int sc = arr[i] + fun(i+2, arr, n);
        
        int ans = max(fr, sc);
        
        // memoize the value so that "DRY"(dont repeat yourself)
        return dp[i] = ans;   
    }
 
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {   
        memset(dp, -1, sizeof(dp));
        int ans = fun(0, arr, n);
        return ans;
    }
};