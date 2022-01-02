Que-
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
Given an integer n, return the nth ugly number.


#define ll     long long

class Solution{
public: 
    // #define ull unsigned long long
    /* Function to get the nth ugly number*/
    ull getNthUglyNo(int n) {
        
        deque<ll> d2;
        deque<ll> d3;
        deque<ll> d5;

        if(n == 1){return 1;}

        for(int i = 1; i < n; i++){
            if(i == 1) {
                d2.push_front(2); 
                d3.push_front(3); 
                d5.push_front(5);
            }
            else {
                ll mn = min(d5[0], min(d2[0], d3[0]));
                
                d2.push_back(2 * mn);
                d3.push_back(3 * mn);
                d5.push_back(5 * mn);

                if(mn == d2[0]) d2.pop_front();
                if(mn == d3[0]) d3.pop_front();
                if(mn == d5[0]) d5.pop_front();
            }
        }
        ll ans = min(d5[0], min(d2[0], d3[0]));
        return ans;
    }
};