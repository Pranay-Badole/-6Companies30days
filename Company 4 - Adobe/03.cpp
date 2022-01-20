Number of distict Words with k maximum contiguous vowels
Que - Find the number of unique words consisting of lowercase alphabets only of length N that can be formed with at-most K contiguous vowels. 


Wasted a lot time figuring out a combinatorics solution but it boiled down to just a simple dp problem.

class Solution
{
    int M = 1e9 + 7;
    
  public:
  int dp[1002][1002];
  
//   i is the current index of the  word 
//   j is the count of contiguous vowels just before the current index i

  long long fun(int i, int j, int &k, int &n) {
      
        // if the cnt of contiguous vowel reaches greater than limit 'k', it violates the condition given
        if(j > k) return 0;
        
        // if we reach the end then this word can be formed
        if(i >= n) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        long long ans;
        
        // choosing current char as consonant(total = 21) 
        long long fr = (21 * fun(i+1, 0, k, n)) % M;
        
        // choosing current char as vowel (total = 5)
        // incrementing j 
        long long sc = (5 * fun(i+1, j+1, k, n)) % M;
         
        ans = (fr + sc) % M;
        return (dp[i][j] = ans);
    }
  
    int kvowelwords(int n, int k) {
        
        memset(dp, -1, sizeof dp);
        int ans = fun(0, 0, k, n);    
        return ans;
    }
};