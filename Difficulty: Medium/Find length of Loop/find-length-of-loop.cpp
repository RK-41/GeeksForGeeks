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
    int lengthOfLoop(Node *head) {
        // code here
        // 06.09.25 (POTD)
        if(!head)   return 0;
        
        int ans=0;
        Node *h=head, *slow=head, *fast=head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
                break;
        }
        
        if(!fast || !fast->next)    return 0;
        
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        
        do{
            ans++;
            fast = fast->next;
        }while(slow != fast);
        
        return ans;
    }
};