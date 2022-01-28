**Transform to Sum Tree**

Que-
Given a Binary Tree of size N , where each node can have positive or negative values. 
Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree.
The values of leaf nodes are changed to 0


Solution-
make a function whose job is basically to return the sum of whole tree rooting from that node
and do recursion.

int fun(Node *root){
    
    if(!root) return 0;
    
    int old = root -> data;
    
    int left = fun(root -> left);
    int right = fun(root -> right);
    
    root -> data = left + right;
    
    return (root -> data + old);
}

void toSumTree(Node *root)
{   
    if(!root) return;
    
    fun(root);
}