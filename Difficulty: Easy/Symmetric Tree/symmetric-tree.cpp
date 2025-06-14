/*
Structure of the node of the tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node* root)
    {
	    // Code here
	    // 14.06.25 (POTD)
	    
	    return check(root, root);
    }
    
    bool check(struct Node* r1, struct Node* r2){
        if(!r1 && !r2)  return true;
        if(!r1 && r2)   return false;
        if(r1 && !r2)   return false;
        
        if(r1->data != r2->data)    return false;
        
        return check(r1->left, r2->right) && check(r1->right, r2->left);
    }
    
};
