Given two library versions of an executable: for example, “10.1.1.3” and “10.1.1.9” or “10” and “10.1”. 
Find out which one is more recent? Strings can be empty also.



#define sz(x)   (int)((x).size())

// function which will return the string which is more recent
string more_recent(string &a, string &b) {
    
    int i = 0;
    int j = 0;

    while(i < sz(a) && j < sz(b)){
        int fr = 0, sc = 0;
        while(i < sz(a) && a[i] != '.') {
            fr = fr * 10 + (int)(a[i] - '0');
            i++;
        }
        while(j < sz(b) && b[j] != '.') {
            sc = sc * 10 + (int)(b[j] - '0');
            j++;
        }
        trace(fr, sc);

        if(fr < sc) return b;
        if(sc < fr) return a;

        i++;
        j++;
    }

    if(i >= sz(a) && j >= sz(b)){
        return "both same";
    }
    if(i >= sz(a)) return b;

    return a;
}