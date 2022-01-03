Que-

For two strings s and t, we say "t divides s" if and only if s = t + ... + t (i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.


// Soln 1.
// trying every possible prefix

class Solution {
public:
    
    string get(int n, string &t){
        if(n == 0) return "";
        string temp = get(n / 2, t);
        temp = temp + temp;
        if(n & 1) temp += t;

        return temp;
    }
    
    int check(string &t, string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        int z = t.size();
        if(m % z) return 0;
        
        string t1 = get((n/z), t);
        string t2 = get((m/z), t);
        
        if((t1 == s1) && (t2 == s2)) {
            return 1;
        }
        return 0;
    }
    
    string gcdOfStrings(string s1, string s2) {
        if(s2.size() < s1.size()) {
            swap(s1, s2);
        }
        int n = s1.size();
        vector<int> v;
        
        for(int i = 1; i * i <= n; i++){
            if(n % i == 0){v.push_back(i);}
            if(i != n/i) v.push_back(n/i);
        }
        sort(v.begin(), v.end());
        
        for(int i = 0; i < v.size(); i++) {
            int m = (n/v[i]);
            string t = s1.substr(0, m);
            int temp = check(t, s1, s2);
            if(temp) return t;
        }
        return "";
    }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Soln 2.
// gcd concept

class Solution {
public:

    string gcdOfStrings(string s1, string s2) {
        if((s1 + s2) == (s2 + s1)){
            return s1.substr(0, __gcd(s1.size(), s2.size()));
        }
        return "";
    }
};




