Que-
Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count 
of the number of subtress having total node’s data sum equal to the value X.
Example: For the tree given below:            

               5
             /    \
           -10     3
          /  \    /  \
         9    8  -4  7

Subtree with sum 7:
             -10
            /   \
           9     8

and one node 7.

Soln- Lets make a recursive function which returns the sum of the tree and a parameter in the function 'ans' which will store the count trees with sum 'x';


int fun(Node* root, int x, int &ans) {
    if(!root) return 0;
        
    // get sum of left subtree
    int sum = fun(root -> left, x, ans);

    // get sum of right subtree
    sum += fun(root -> right, x, ans);
    
    // the sum of whole tree originating from current node
    sum += root -> data;
    
    // check if sum of current tree originating from current node is 'x' 
    // if sum is x increase count 'ans';
    if(sum == x) ans++;
    
    return (sum);
}

int countSubtreesWithSumX(Node* root, int X)
{
	int ans = 0;
	fun(root, X, ans);
	return ans;
}