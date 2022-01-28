**Number of Unique Paths**

Que-
Given a A X B matrix with your initial position at the top-left cell, find the number of possible 
unique paths to reach the bottom-right cell of the matrix from the initial position.

Note: Possible moves can be either down or right at any point in time, i.e., 
we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].


Solution:
We have to move from top left to bottom right.

So,
no of rights we will be taking in the path = width of matrix(B) - 1;
no of downs we will be taking in the path = height of matrix(A) - 1;

so for (4 X 3) it will be
R - 3-1 = 2
D - 4-1 = 3

so path will comprise of "RRDDD" in total.

we just have to find the total no of permutations possible for it.

which is   ans = (fact(a + b - 2) / (fact(a-1)*fact(b-1)));

but for (15 X 15)
fact(28)
checkout for overflow 



class Solution
{
    public:
    //Function to find total number of unique paths.
    
    long long fact(int n){
        if(n == 0) {
            return 1;
        }
        return (n * fact(n-1));
    }
    
    int NumberOfPath(int a, int b)
    {
        a--;b--;
        if(a < b) swap(a, b);
        long long ans = 1;
        
        for(int i = a+1; i <= a+b; i++) {
            ans *= i;
        }
        ans /= fact(b);
        
        return ans;
    }
};