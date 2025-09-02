/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int K) {
        // code here
        // 02.09.25 (POTD)
        Node* h=head;
        int n = 0;
        while(h){
            n++;
            h = h->next;
        }
        if(K>n) return head;
    
        h = head;
        Node* ans[n];
        int i=0;
        while(h){
            ans[i++]=h;
            h=h->next;
        }
        swap(ans[K-1],ans[n-K]);
        head=ans[0];
        h=head;
        
        i=1;
        while(i<n){
            h->next=ans[i++];
            h=h->next;
        }
        h->next=NULL;
        return head;
    }
};