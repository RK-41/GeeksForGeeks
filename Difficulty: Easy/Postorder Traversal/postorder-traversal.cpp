/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // 09.10.25 (POTD)
    void post(Node* r, vector<int>&v){
    if(r==NULL) return;
    
    post(r->left,v);
    post(r->right,v);
    v.push_back(r->data);
    }
    //Function to return a list containing the postorder traversal of the tree.
    vector <int> postOrder(Node* root)
    {
      // Your code here
      if(root==NULL)    return {-1};
      
      vector<int> ans;
      post(root,ans);
      return ans;
    }
};