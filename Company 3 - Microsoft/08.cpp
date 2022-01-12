Que-
Given a binary tree, connect the nodes that are at same level. Youll be given an addition nextRight pointer for the same.

Initially, all the nextRight pointers point to garbage values. Your function should set these pointers to point next right for each node.
       
       10                        10 ---> NULL
      / \                       /  \
     3   5       =>            3--->5 ---> NULL
    / \   \                   / \    \
   4   1   2                 4-->1--->2 ---> NULL


Soln-
do level order traversal of the tree and unlike normal traversal take all the elements present in the queue all together at once
we will do it by noting first the size 'n' of of the current queue and then store all the first n elements of queue in array, so at a particular iteration
we have all the Nodes at a specific level then just "prev -> nextRight = cur" you dont even need a vector to store, we just need last node

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node* root)
    {
        queue<Node*> q;
        q.push(root);
        
        while(q.size()) {
            int n = q.size();
            Node* last = NULL;
            while(n--) {
                auto top = q.front();
                q.pop();
                
                if(top -> left) q.push(top -> left);
                if(top -> right) q.push(top -> right);
                
                if(last != NULL){
                    last -> nextRight = top;
                }
                last = top;
            }
            last -> nextRight = NULL;
        }
        
    }    
      
};