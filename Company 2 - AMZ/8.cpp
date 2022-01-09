Que-

// There are N stairs, and a person standing at the bottom wants to reach the top. 
// The person can climb either 1 stair or 2 stairs at a time. Count the number of ways, 
// the person can reach the top (order does not matter).

Note: Order does not matter means for n = 4 {1 2 1},{2 1 1},{1 1 2} are considered sam

Soln -
// LoL xp one liner
// just count how many 2's can be in a particular way 
// that can be 0, 1, 2.......

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair 
    //when order does not matter.

    long long countWays(int m)
    {
       return ((m / 2) + 1);
    }
};