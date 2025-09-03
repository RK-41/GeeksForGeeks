/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        // 03.09.25 potd
        Node* curr=head;
        Node* prev=NULL;
        Node* nxt=NULL;
        
        while(curr!=NULL){
            nxt=curr->next;
            curr->next=prev;
            curr->prev=nxt;
            prev=curr;
            curr=nxt;
        }
        
        return prev;

    }
};