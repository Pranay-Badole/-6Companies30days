Que-

// Find total number of Squares in a N*N cheesboard.

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // # of squares of size 1 ==> N * N;
        // # of squares of size 2 ==> (N-1) * (N-1);
        // # of squares of size 3 ==> (N-2) * (N-2);
        // ans so on till size <= N
        
        // this is basically sum of squared 1st n natural numbers.
        
        long long ans = (N * (N + 1) * ((2 * N) + 1)) / 6;
        return ans;
    }
};