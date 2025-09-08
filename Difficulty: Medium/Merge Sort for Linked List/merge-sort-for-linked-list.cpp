/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

// 08.09.25 (POTD)
class Solution{
  public:
    // Function to get mid
    Node* getMid(Node* head){
        if(head==NULL || head->next==NULL)  return head;
        
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        // fast will be at the end, slow will be at the mid
        
        return slow;
    }
    
    // Function to merge the LL
    Node* merge(Node* left, Node* right){
        if(!left)   return right;
        if(!right)  return left;
        
        if(left->data <= right->data){
            left->next=merge(left->next,right);
            return left;
        }
        else{
            right->next=merge(right->next,left);
            return right;
        }
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL)  return head;
        
        Node* mid=getMid(head);
        Node* left=head;
        Node* right=mid->next;
        
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        
        return merge(left,right);
    }
};

