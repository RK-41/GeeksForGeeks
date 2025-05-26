/* structure for a node
class Node {
 public:
  int data;
  Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
}; */

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        // 26.05.25 POTD
        Node *hd = head;
        
        if(hd->data >= data){
            while(hd->next != head)
                hd = hd->next;
        } else {
            while(hd->next->data <= data and hd->next != head)
                hd = hd->next;
        }
        
        Node *nd = new Node(data);
        nd->next = hd->next;
        hd->next = nd;
        
        if(head->data >= data){
            head = nd;
        }
        
        return head;
    }
};