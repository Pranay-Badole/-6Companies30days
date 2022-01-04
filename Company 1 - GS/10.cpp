Que-
// Find max 'K' numbers in a list having N(10M) entries.

// as we have to go through all 10M entries so the complexity will definately be O(N ~ 10M);
// now if take whole input and then sort it it will be O(N*log N);

// we can do better by maintaining a min heap of 10 numbers and as we take input we insert it into heap
// and if its size goes beyond 10 we will take out the "min" element and we will be left with 10 max elements at any instance.
    // O(N * log(10)) ~ O(N);

    void solve(){
    
        priority_queue<ll, vector<ll>, greater<ll>> pq;        

        ll N, K, t; 
        cin >> N >> K;

        while(N--){
            cin >> t;
            pq.push(t);
            if(pq.size() > K){
                pq.pop();
            }
        }

        while(pq.size()) {
            cout << pq.top() << ' ';
            pq.pop();
        }
    }