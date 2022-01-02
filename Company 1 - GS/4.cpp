Que-
// Given a string, Your task is to  complete the function encode that returns the run length encoded string for the given string.
// eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
// You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

string encode(string src)
{     
    int cnt = 0;
    char c = src[0];
    string ans = "";
    
    for(int i = 0; i < src.size(); i++) {
        if(src[i] == c) cnt++;
        else {
            ans += c;
            ans += to_string(cnt);
            cnt = 1;
            c = src[i];
        }
    }
    ans += c;
    ans += to_string(cnt);
    return ans;
}