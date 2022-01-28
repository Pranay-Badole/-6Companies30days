**Power Of Numbers**

Que-
Given a number and its reverse. Find that number raised to the power of its own reverse.
Note: As answers can be very large, print the result modulo 109 + 7.

Solution-

Modular Exponentiation (Power in Modular Arithmetic):
if you dont know it, come back after learning. It is very useful in finding powers efficiently.


class Solution{
    public:
    //You need to complete this fucntion
    const int M = 1e9 + 7;
    
    long long fun(int n, int m) {
        if(m == 0) return 1;
        
        long long temp = fun(n, m/2);
        temp = (temp * temp) % M;
        
        if(m & 1) temp = (temp * n) % M;
        
        return temp;
    }
    
    long long power(int N,int R)
    {
       
        long long ans = fun(N, R);
        return ans;   
    }

};