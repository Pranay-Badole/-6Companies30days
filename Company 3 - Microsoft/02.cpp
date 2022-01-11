Que- There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]

Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Soln-

This question boils down to checking cycle in a graph 
which can easily be done by colouring graph nodes 
			:"0" as yet to be visited 
			:"1" as visited 
			:"2" this node has been checked already need not to check this one

and if we get a node as ("1") while traversing then we got a cycle
else after checking complete forest we are clear no cycle found




class Solution {
public:

    void dfs(int i, vector<vector<int>> &adj, vector<int> &vis, int &flag) {
        if(vis[i] == 2) return;
        
        if(vis[i] == 1) {flag = 1; return;}
        vis[i] = 1;
        
        for(auto x : adj[i]) {
            dfs(x, adj, vis, flag);
        }
        vis[i] = 2;
    }

	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);	 
	    
	    for(auto pr : prerequisites) {
	        adj[pr.first].push_back(pr.second);
	    }
	   	
	    vector<int> vis(N, 0);
	    for(int i = 0; i < N; i++){
	        if(vis[i] == 0){
	            int flag = 0;
	            dfs(i, adj, vis, flag);
	            if(flag) return 0;
	        }
	    }
	    return 1;
	 }
};