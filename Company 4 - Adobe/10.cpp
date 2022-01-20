**Winner of an election**

Given an array of names Given an array of names (consisting of lowercase characters) of candidates in an election. 
A candidate name in array represents a vote casted to the candidate. Print the name of candidate that received Max votes.
If there is tie, print lexicographically smaller name.



Soln-
SIMPLE IMPLEMENTATION PROBLEM

class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string, int> cnt;
        
        for(int i = 0; i < n; i++) cnt[arr[i]]++;
        
        int mx = -1;
        string ans = "";
        
        for(auto x : cnt){
            if(x.second > mx) {mx = x.second; ans = x.first;}
            else if(x.second == mx && (x.first < ans)) {
                ans = x.first;
            }
        }
        vector<string> res;
        res.push_back(ans);
        res.push_back(to_string(mx));
        
        return res;
    }
};