Que- Given a number N. The task is to generate and print all binary numbers with decimal values from 1 to N.


Soln-
Yes, the basic soln is to generate binary string for every number from 1 --> N.
taking Nlog2(N);

BN - binary number

I tried differently generating binary no for current element using BN of prev 
element as for the current no we have to just add '1' to the prev BN.
and adding '1' is nothing but finding the least significant "unset" bit turning it into "set" and all the bits after that to "unset"


vector<string> generate(int N)
{
	string s = "0";
	int j = 0;
	vector<string> ans;
	
	while(j < N){
	    int i = s.size() - 1;

	    while(i >= 0 && s[i] != '0'){
	        s[i] = '0';
	        i--;
	    }
	    if(i >= 0) s[i] = '1';
	    else s = '1' + s;
	    
	   // cout << s << ' ';
	    ans.push_back(s);
	    j++;
	}
	
    return ans;
}