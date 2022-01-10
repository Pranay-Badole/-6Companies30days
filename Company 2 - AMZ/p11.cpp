Que-

// Serialize and Deserialize a tree.
// Serialize it into an arrray of inorder traversal of tree
// then deserialize it into a tree whose inorder is the given array.



class Solution
{
    public:

    // do preorder traversal, just instead of printing element
    // push it into vector

    void dfs(Node *root, vector<int> &ans) {
        if(!root) return;
        dfs(root -> left, ans);
        ans.push_back(root -> data);
        dfs(root -> right, ans);
    }
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    // divide and conquer
    // ###for a balanced BT: 
            // select the mid, 
            // the elements on the left of mid will form its left child node
            // the elements on the right of mid will form its right child node
    
    // ###for a skewed tree(not recommended, it will just be a LL not tree)
            // on iterating array from front to end, 
            // add the next element on the left child node of the current element

    Node* form(int l, int r, vector<int> &v) {
        
        if(l > r) return NULL;
        
        int mid = l + (r - l)/2;
        Node* head = new Node(v[mid]);
        head -> left = form(l, mid - 1, v);
        head -> right = form(mid + 1, r, v);
        return head;
        
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &v)
    {   
        int n = v.size();
        Node *head = form(0, n-1, v);
        return head;
        
    }
};