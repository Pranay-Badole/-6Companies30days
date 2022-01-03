Que-

// M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.
// Examples : 
// Input : N = 5
//         M = 2
//         K = 1

// Output : 2
// The first item will be given to 1st 
// position. Second (or last) item will 
// be delivered to 2nd position

// Input : N = 5 
//         M = 8 
//         K = 2

// Output : 4
// The last item will be delivered to 
// 4th position


// n --> size of circle
// m --> no of gifts to be delivered
// k --> starting position

void solve(){
    
    ll n, m, k;
    cin >> n >> m >> k;

    ll steps = ((m - 1) % n);
    ll start = k - 1; 

    ll end = (start + steps) % n;
    end = start + 1;

    cout << start;

}