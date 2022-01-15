Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 
if the order of string returned by the function is correct else 0 denoting incorrect string returned.


Soln - 
The core of this question is topological sort. We have to get precedence of alphabets according to the dictionary given, 
if the input is correct (as in normal dictionary), then precedence will be in the form such that there is no cycle in the precedence list and will be directed
thus first we will form the adjancey list from the dictionary (directed)
then will use the topological sort to get the answer.

void topo_dfs(int v, vector<vector<int>> &adj, stack<int> &st, vector<int>& vis) {
    vis[v] = 1;
    for(auto to : adj[v]) {
        if(!vis[to]){
            topo_dfs(to, adj, st, vis);
        }
    }
    st.push(v);
}

class Solution{
    public:
    string findOrder(string dict[], int N, int n) {
        vector<vector<int>> adj(n);
        string ans = "";
        
        for(int i = 0; i < N-1; i++){
            string &s = dict[i];
            string &t = dict[i+1];
            int sz = min(s.size(), t.size());
            
            for(int j = 0; j < sz; j++) {
                if(s[j] != t[j]){
                    // cout << s[j] << ' ' << t[j] << " | ";
                    adj[s[j]-'a'].push_back(t[j]-'a');
                    break;
                }
            }
        }

        // for(int i = 0; i < n; i++){
        //     cout << i << " ==> ";
        //     for(auto x : adj[i]){ cout << x << ' ';}
        //     cout << endl;
        // }
        
        stack<int> st;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                topo_dfs(i, adj, st, vis);
            }
        }
        while(st.size()) {char c =  'a' + st.top(); ans += c; st.pop();}

        return ans;
    }
};