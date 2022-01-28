**Path with Maximum Probability**

Que-
You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list 
where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].

Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.

If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.


Solution

Need to grind on shortest path algos, most of the time i solve this without using those like i did here using BFS.

To learn  - Shortest path algos!!!

this is somewhat similar to rotting oranges where we have to farthest oranges.
we will approach in the same way but here instead of dist array we will maintain a probability array
Probability array will store the max prob we can get for an index at any instance, whenever we can reach an index with
a greater probability than what it is in the prob array initially, we will update its prob and push it into queue.

class Solution {
public:
 
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int, double>>> adj(n);
        
        for(int i = 0; i < edges.size(); i++) {
            int fr = edges[i][0];
            int to = edges[i][1];
            double prob = succProb[i];
            
            adj[fr].push_back({to, prob});
            adj[to].push_back({fr, prob});
        }
        
        vector<double> prob(n, 0);
        
        queue<int> q;
        q.push(start);
        prob[start] = 1;
        
        while(q.size()) {
            
            int top = q.front();
            q.pop();
            
            for(auto x : adj[top]) {
                int to = x.first;
                double cost = x.second;
                
                double neww = (prob[top] * cost);
                
                if(prob[to] < neww) {
                    prob[to] = neww;
                    q.push(to);
                }
            }
        }
        return prob[end];
    }
};