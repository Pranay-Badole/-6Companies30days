Given a keypad as shown in the diagram, and an N digit number which is represented by 
array a[], the task is to list all words which are possible by pressing these numbers.


// if someone has solved "find all subsets of a string"
// this one is also similar easily done using recursion


class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    string mp[10];
    
    void fun(int i, int a[], int &N, vector<string> &ans, string &s) {
        if(i >= N){
            ans.push_back(s);
            return;
        }
        for(auto x : mp[a[i]]){
            
            s += x;
            fun(i+1, a, N, ans, s);
            s.pop_back();
        }
    }
    
    vector<string> possibleWords(int a[], int N)
    {   
        mp[2] = "abc"; mp[3] = "def"; mp[4] = "ghi";
        mp[5] = "jkl"; mp[6] = "mno"; mp[7] = "pqrs";
        mp[8] = "tuv"; mp[9] = "wxyz"; 
        
        vector<string> ans;
        string s = "";
        fun(0, a, N, ans, s);
        return ans;
    }
};