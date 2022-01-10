Que-
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
Excel columns has a pattern like A, B, C, … ,Z, AA, AB, AC,…. ,AZ, BA, BB, … ZZ, AAA, AAB...etc.
In other words, column 1 is named as “A”, column 2 as “B”, column 27 as “AA” and so on.


// A little bit tricky, good question
// next no in the recursive stack should be "(n-1)/26" not "n/26" it gives wrong ans

class Solution{
    public:
    
    void fun(long long n, string &s) {
        if(n == 0ll) return;
        char t = 'A' + ((n-1) % 26);
        s = t + s;

        fun((n-1)/26, s);
    }
    
    string colName (long long int n)
    {   
        string s = "";
        fun(n, s);
        
        return s;
    }
};