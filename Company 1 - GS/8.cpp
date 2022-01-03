Que-

// A top secret message containing letters from A-Z is being encoded to numbers using the following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// You are an FBI agent. You have to determine the total number of ways that message can be decoded, as the answer can be large return the answer modulo 109 + 7.
// Note: An empty digit sequence is considered to have one decoding. It may be assumed that the input contains valid digits from 0 to 9 and If there are leading 0’s, extra trailing 0’s and two or more consecutive 0’s then it is an invalid string.

const int MM = 1e9 + 7;

class Solution {

    public:
        int dp[10005];

        int fun(int i, string &s) {
            
            int n = s.size();

// base case

            if(i >= n){return 1;}

// a code can not start with '0'

            if(s[i] == '0') return 0;

            if(dp[i] != -1) return dp[i];
    
// considering single digit and proceeding forward

            int fr = fun(i + 1, s);
            int sc = 0;

// checking for double digit if fine then proceeding forward
            
            if(i < n - 1) {
                int t = stoi(s.substr(i, 2));
                if(t <= 26){
                    sc = fun(i+2, s);
                }
            }
            
            int ans = (fr + sc) % MM;
            return dp[i] = ans;
        }
    
        int CountWays(string str){
            
            memset(dp, -1, sizeof(dp));
            int ans = fun(0, str);
            return ans;
            
        }
};