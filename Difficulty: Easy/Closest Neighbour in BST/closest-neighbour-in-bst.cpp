/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        // 30.05.25 POTD
        int ans = -1;
        inorder(root, ans, k);
        
        return ans;
    }
    
    void inorder(Node* nd, int &ans, int k){
        if(!nd) return;
        
        inorder(nd->left, ans, k);
        
        if(nd->data <= k){
            ans = max(ans, nd->data);
        }
        
        inorder(nd->right, ans, k);
        
    }
};