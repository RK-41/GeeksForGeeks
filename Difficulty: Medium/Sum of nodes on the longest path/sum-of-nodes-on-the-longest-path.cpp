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
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        // 29.05.25 (POTD)
        if(!root)   return 0;
        
        int ans=root->data;
        queue<pair<Node*,int>> q;
        
        q.push({root,root->data});
        
        while(q.size()){
            int sz = q.size();
            vector<int> v;
            ans=0;
            
            while(sz--){
                auto f = q.front();
                q.pop();
                
                Node* nd = f.first;
                int sum = f.second;
                
                if(!nd->left && !nd->right){
                    ans = max(ans, sum);
                    continue;
                }
                
                if(nd->left){
                    int lsum = nd->left->data + sum;
                    q.push({nd->left, lsum});
                }
                
                if(nd->right){
                    int rsum = nd->right->data + sum;
                    q.push({nd->right, rsum});
                }
            }
        }
        
        return ans;
    }
};