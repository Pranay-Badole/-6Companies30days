Que-
Given a number K and string str of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of str at most K times.

Example 1:

Input:
K = 4
str = "1234567"
Output:
7654321
Explanation:
Three swaps can make the input 1234567 to 7654321, swapping 1 with 7, 2 with 6 and finally 3 with 5.

Solution-
Basic intuition is to replace the current index with the maximum element in the string following and including current index: basically (idx -> end);

I wasted a lot of time figuring out a greedy solution to pick the optimum element index to swap among all the maximum element indexes available but it didnt work.

Bruteforcing is the key here but the complexity of it is in exponential O(n^k) which refrained me from following that approach at first, but it somehow passed, when I tried after quite a long time.


So,
for every index 'i' we will choose all the indexes of the maximum elements available and bruteforce the answer.


##BACKTRACKING

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void fun(string &str, int i, int &n, int k, string &ans) {
        
        if(i >= n || k == 0) {
            ans = max(ans, str);
            return;
        }
        
        char mx = (char)('1' - 10);
        
        for(int j = i; j < n; j++){
            mx = max(mx, str[j]);    
        }
        if(mx == str[i]) {fun(str, i+1, n, k, ans);return;}
        
        for(int j = i; j < n; j++) {
            if(str[j] == mx){
                swap(str[i], str[j]);
                fun(str, i+1, n, k-1, ans);
                swap(str[i], str[j]);
            }
        }
        return;
    }
    
    string findMaximumNum(string str, int k)
    {   
        int n = str.size();
        string ans = "";
        fun(str, 0, n, k, ans);
        return ans;
        
    }
};


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

##GREEDY ❌❌❌ 
not correct

class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    int find_max(string &str, int i) {
        int mx = -1;
        for(i; i < str.size(); i++) {
            if(mx == -1 || str[mx] <= str[i]){
                mx = i;
            }
        }
        return mx;
    }
    
    string findMaximumNum(string str, int k)
    {   
        int last = 0;
        vector<vector<int>> v(10);
        
        for(int i = 0; i < k; i++) {
            while(last < str.size()){
                int idx = find_max(str, last);
                if(str[last] == str[idx]){
                    last++;
                    continue;
                }
                swap(str[last], str[idx]);
                v[(str[last] - '0')].push_back(idx);
                last++;
                break;
            }
            cout << str << endl;
            if(last >= str.size()) break;
        }
        
        for(int i = 0; i < 10; i++) {
            if(!v[i].size()) continue;
            cout << i << "==> ";
            for(auto x : v[i]) {cout << x << ' ';}
            cout << endl;
        }
        cout << str << endl;
        for(int i = 0; i < 10; i++) {
            sort(v[i].begin(), v[i].end());
          vector<char> t;
          for(auto x : v[i]) {t.push_back(str[x]);}
          sort(t.begin(), t.end(), greater<int>());
           
          for(int j = 0; j < t.size(); j++) {
              str[v[i][j]] = t[j];
          }
        }
        
        return str;
    }
};