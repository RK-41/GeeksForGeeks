/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    /*  Function which returns the  root of 
        the flattened linked list. */
    Node *flatten(Node *root)
    {
       // Your code here
       // 03.01.26 (potd)
       if(root==NULL)   return root;
       
       Node* y=flatten(root->next);
       return merge(root,y);
    }
    // MERGE FUNCTION
    Node* merge(Node* x, Node* y){
        if(y==NULL) return x;
        
        Node* ans=new Node(0);
        Node* a=ans;
        
        while(x!=NULL || y!=NULL){
            if(y==NULL || (x!=NULL && x->data<y->data)){
                a->bottom=x;
                x=x->bottom;
            }
            else{
                a->bottom=y;
                y=y->bottom;
            }
            a=a->bottom;
        }
        
        return ans->bottom;
    }
};