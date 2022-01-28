**Remove Colored Pieces if Both Neighbors are the Same Color**

Que-

There are n pieces arranged in a line, and each piece is colored either by 'A' or by 'B'. 
You are given a string colors of length n where colors[i] is the color of the ith piece.

Alice and Bob are playing a game where they take alternating turns removing pieces from the line. 
In this game, Alice moves first.

Alice is only allowed to remove a piece colored 'A' if both its neighbors are also colored 'A'. She is not allowed to remove pieces that are colored 'B'.

Bob is only allowed to remove a piece colored 'B' if both its neighbors are also colored 'B'. He is not allowed to remove pieces that are colored 'A'.

Alice and Bob cannot remove pieces from the edge of the line.

If a player cannot make a move on their turn, that player loses and the other player wins.
Assuming Alice and Bob play optimally, return true if Alice wins, or return false if Bob wins.


Solution-

You can notice that removing a piece by player 1, can not have any impact on the total no of pieces that can be removed by 2nd player.

So the total no of pieces removed by a player will be the same no matter in which order he picks.

So we will count the total no of pieces that can be removed by Alice and Bob respectively (ta, tb).

if(ta > tb) alice wins 
else alice loses

class Solution {
public:
    bool winnerOfGame(string v) {
        int n = v.size();
        
        int t1, t2;
        t1 = t2 = 0;
        
        int cnt = 1;
        
        for(int i = 1; i < n; i++) {
            if(v[i] == v[i-1]) {
                cnt++;
            }
            else {
                if(v[i] == 'B') {
                    t1 += max(cnt-2, 0);
                    cnt = 1;
                }
                else{
                    t2 += max(cnt - 2, 0);
                    cnt = 1;
                }
            }
        }
        if(v[n-1] == 'A') t1 += max(cnt-2, 0);
        else t2 += max(cnt-2, 0);
        
        // cout << t1 << ' ' << t2 << endl;
        return (t1 > t2);
    }
};

