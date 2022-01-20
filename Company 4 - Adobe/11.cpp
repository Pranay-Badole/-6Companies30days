**Amend The Sentence**

Que - 
Given a string which is basically a sentence without spaces between words. However the first letter of every word is in uppercase. 
You need to print this sentence after following amendments:
(i) Put a single space between these words
(ii) Convert the uppercase letters to lowercase.

Soln-
SIMPLE IMPLEMENTATION PROBLEM

class Solution{
    public:
    string amendSentence (string s)
    {
        string temp = "";
        
        for(auto &x : s){
            if(isupper(x) && temp != "") {
                temp += ' ';
            }
            temp += tolower(x);
        }
        return temp;
    }
};