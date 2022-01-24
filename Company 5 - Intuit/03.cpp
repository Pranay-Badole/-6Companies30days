Que - find the missing number fromt the string

Given a string consisting of some numbers, not separated by any separator. 
The numbers are positive integers and the sequence increases by one at each number except the missing number. 
The task is to complete the function missingNumber which returns the missing number. The numbers will have no more than six digits. 
Print -1 if input sequence is not valid.


Basically we have a string which contains consecutive numbers, appended without space between numbers.

like lets start with 18 taking 6 numbers

then 18 19 20 21 22 23
    it will be --> "181920212223"

and after removing a number suppose 21
we have final string as --> "1819202223"


Solution:

We will brute force for the no of digits in the starting number.
It is imp to note that the numbers can have at most 6 digits (given in statement) so we will iterate from
1 to 6 as the no of digits and try to find the answer for each.




int check(int k, string s) {
    
    int cur = 0;
    int miss = -1;
    int i = 0;
    
    for(i = 0; i < k; i++) {
        cur = (cur * 10) + (s[i] - '0'); 
    }
    
    while(i < s.size()) {
        cur++;
        // cout << i << ' ' << cur << endl;
        int val = 0;
        while(val < cur){
            val = (val * 10) + (s[i] - '0'); 
            i++;
        }
        if(val != cur){
            if(miss != -1 || val != cur + 1) return -1;
            if(val == cur + 1) {
                miss = cur;
                cur++;
            }
        }
    }
    
    return miss;
}

int missingNumber(const string& s)
{   
    int n = s.size();
    int z = min(n, 6);
    
    for(int i = 1; i <= z; i++) {
        int ans = check(i, s);
        if(ans != -1) return ans;
    }
    return -1;
}