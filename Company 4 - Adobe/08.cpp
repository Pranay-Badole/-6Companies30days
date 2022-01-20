** Implement Atoi **

Your task  is to implement the function atoi. The function takes a string(str) as argument and converts it to an integer and returns it.


class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        int ans = 0;
        int neg = 1;
        
        if(str[0] == '-') {neg = -1;str = str.substr(1);}
        
        for(auto &x : str){
            if(!isdigit(x)) return -1;
            
            ans = (ans * 10) + (int)(x - '0');
        }
        return (ans*neg);
    }
};