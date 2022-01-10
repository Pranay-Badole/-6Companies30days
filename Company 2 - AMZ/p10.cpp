Que-
Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
The elements should follow the following order ! # $ % & * @ ^ ~

Soln-
// Complicated question but very easy solution

class Solution{
public:	

	void matchPairs(char nuts[], char bolts[], int n) {
	    string s = "!#$%&*@^~";
	    unordered_set<char> st;
	    for(int i = 0; i < n; i++) {st.insert(nuts[i]);}
	    
	    int j = 0;
	    
	    for(int i = 0; i < 9; i++) {
	        if(st.count(s[i])) {
	            nuts[j] = bolts[j] = s[i];
	            j++;
	        }
	    }
	}
};