Que- Given a linked list, delete N nodes after skipping M nodes of a linked list until the last of the linked list.

Example:
Input:
2
8
2 1
9 1 3 5 9 4 10 1
6
6 1
1 2 3 4 5 6

Output: 
9 1 5 9 10 1
1 2 3 4 5 6

// implementation problem
// just be careful about edge cases where next node is nullptr

class Solution
{
    public:
    void linkdelete(struct Node* head, int M, int N)
    {
        Node *temp = head;
        
        while(temp){
            int m = M-1;
            while(m--){
                if(!temp -> next) return;
                temp = temp -> next;
            }
            Node *last = temp;
            int n = N+1;
            while(n--){
                if(!temp -> next) {temp = temp -> next; break;}
                temp = temp -> next;
            }
            last -> next = temp;
        }
    }
};