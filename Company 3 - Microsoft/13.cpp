Que- Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the
given edge is a Bridge. i.e., removing the edge disconnects the graph.


Soln - find all the bridges in a graph and check if the given edge "c--d" is among them or not;

alternate method is to check all the connected componnents in the graph initially say "N"
and all the connected components after removing the given edge "c--d" say "M"
if M > N then it is bridge edge else it is not;

class Solution
{
	public:
	int timer = 0;
	vector<int> vis;
	vector<int> tin;
	vector<int> low;
	
	void dfs(int v, int par, vector<int> adj[], int &c, int &d, int &flag) {
	    
        vis[v] = 1;
	    low[v] = tin[v] = timer++;
	    
	    for(auto to : adj[v]) {
            if(to == par) continue;
            
            if(!vis[to]){
                dfs(to, v, adj, c, d, flag);
            }
            
            if(low[to] > tin[v]){
                // cout << to   << ' ' << v << endl;
                if(((to == c) && (v == d)) || ((to == d) && (v == c))){
                    flag = 1;
                }
    	    }
            low[v] = min(low[v], low[to]);
	    }
	}
	
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int n, vector<int> adj[], int c, int d) 
    {
        vis.resize(n, 0);
        tin.resize(n, -1);
        low.resize(n, -1);
        
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                timer = 0;
                dfs(i, -1, adj, c, d, ans);
                if(ans) return ans;
            }
        }
        
        return ans;
    }
};