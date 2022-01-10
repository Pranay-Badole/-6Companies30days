Que- Given a binary tree and a node called target. Find the minimum time required to
burn the complete binary tree if the target is set on fire. It is known that in 1 
second all nodes connected to a given node get burned. That is its left child, right child, and parent.

Soln-
make adjacency list of the whole tree then just do dfs to find the farthest point from the target node


#define fr      first
#define sc      second

class Solution {
  public:
  
    int dfs(int t, map<int, vector<int>> &mp, unordered_set<int> &st){
        
        int ans = INT_MIN;
        int flag = 0;
        
        for(auto x : mp[t]){
            if(!st.count(x)){
                flag = 1;
                st.insert(x);
                ans = max(ans, dfs(x, mp, st));
                st.erase(x);
            }
        }
        if(!flag) return 0;
        
        return ans + 1;
    }
  
    int minTime(Node* root, int t) 
    {
        map<int, vector<int>> mp;
        
        priority_queue<Node*> pq;
        pq.push(root);
        
        while(pq.size()) {
            auto top = pq.top();
            pq.pop();
            
            if(top -> left){
                mp[top -> data].push_back(top -> left -> data);
                mp[top -> left -> data].push_back(top -> data);
                pq.push(top -> left);
                
            }
            if(top -> right){
                mp[top -> data].push_back(top -> right -> data);
                mp[top -> right -> data].push_back(top -> data);
                pq.push(top -> right);
            }
        }
        
        // for(auto x : mp){
        //     cout << x.fr << "==>";
        //     for(auto y : x.sc){
        //         cout << y << ' ';
        //     }
        //     cout << endl;
        // }
        
        unordered_set<int> st;
        st.insert(t);
        int ans = dfs(t, mp, st);
        return ans;
    }
};