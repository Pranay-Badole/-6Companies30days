**Generate Parentheses**

Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.


//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses

class Solution
{
    public:

    l - no of opening brackets
    r - no of closing brackets

    void fun(int l, int r, string &st, int n, vector<string> &ans) {

    // if no of opening brackets is greater than n, it violates the condition
        if(l > n) return;

    // a string of parantheses is valid only if at any index the cnt of all '(' till that index is greater tha or equal to cnt of all ')';
        if(r > l) return;

    // if we reach the BC add the string to collection
        if(l == r && l == n){
            ans.push_back(st);
            return;
        }

        // try opening bracket
        st += '(';
        fun(l+1, r, st, n, ans);
        st.pop_back();
        
        // try closing bracket
        st += ')';
        fun(l, r+1, st, n, ans);
        st.pop_back();
        
    }
    vector<string> AllParenthesis(int n) 
    {   
        string st = "";
        vector<string> ans;
        fun(0, 0, st, n, ans);
        return ans;
    }
};