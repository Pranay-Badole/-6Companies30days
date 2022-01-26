**Construct Quad Tree**
GOOD QUESTION

Que-
Statement is a little bit complex read it here: https://leetcode.com/problems/construct-quad-tree/


Solution-

Firstly, we need to represent a matrix somehow and its size, so that we can iterate over all the elements in that matrix to check if it is a leaf or not.

for that I am representing a matrix as (i, j, n)
where (i, j) is the top left most point of the matrix and has a size of n.

So first one will start with the matrix given i.e of size n and top most left point will be(0, 0)
==> (0, 0, n)

then its top left portion will be (0, 0, n/2)
top right will be (0, n/2, n/2)
bottom left will be (n/2, 0, n/2)
bottom right will be (n/2, n/2, n/2)

so we will keep on going recursively till we reach the leaf that is all the cells in the matrix are uniform or the size of matrix becomes zero.



class Solution {
public:
    
    Node* fun(int i, int j, int n, vector<vector<int>> &v) {
        if(n == 0) return NULL;
        
        int c0, c1;
        c0 = c1 = 0;
        int flag = 0;
        
        for(int a = i; a < i + n; a++) {
            for(int b = j; b < j+n; b++) {
                if(v[a][b] == 1) c1++;
                else c0++;
                if(c1 && c0) flag = 1;
            }    
        }
        Node *root;
        if(flag){
            root = new Node(0, 0);
            
            root -> topLeft     = fun(i, j, n/2, v);
            root -> topRight    = fun(i, j+(n/2), n/2, v);
            root -> bottomLeft  = fun(i+(n/2), j, n/2, v);
            root -> bottomRight = fun(i+(n/2), j+(n/2), n/2, v);
        }
        else{
            int k = 0;
            if(c1) k = 1;
            
            root = new Node(k, 1);
        }
        
        return root;
    }
    
    Node* construct(vector<vector<int>>& v) {
        int n = v.size();
        Node *root = fun(0, 0, n, v);
        return root;
    }
};
