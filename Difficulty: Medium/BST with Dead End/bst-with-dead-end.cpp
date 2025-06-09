/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:

    void solve(Node* root, int l, int r, bool &flg){
        if(!root)   return;
        if(flg)     return;
    
        if(!root->left && !root->right){
            if(l == r)
                flg = true;
            
            return;
        }
    
        solve(root->left, l, root->data-1, flg);
        solve(root->right, root->data+1, r, flg);
    }

    bool isDeadEnd(Node *root)
    {
        //Your code here
        // 09.06.25 (POTD)
        bool flg=false;
    
        solve(root, 1, INT_MAX, flg);
    
        return flg;
    }
};
