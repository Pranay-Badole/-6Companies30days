// Que-
// Given an array of strings, return all groups of strings that are anagrams. 
// The groups must be created in order of their appearance in the original array. 
// Look at the sample case for clarification.


class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& list) {
        
        unordered_map<string, vector<string>> mp;
        for(auto x : list){
            string y = x;
            sort(y.begin(), y.end());
            mp[y].push_back(x);
        }
        
        vector<vector<string>> ans;
        
        for(auto x : mp){
            ans.push_back(x.second);    
        }
        return ans;
    }
};