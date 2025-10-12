/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int distCandy(Node* root) {
        //code here
        // 12.10.25 (potd)
        int ans=0;
        solve(root, ans);
        return ans;
    }
    
    int solve(Node* r, int &ans) {
        if(!r)  return 0;
        
        int lt=solve(r->left, ans);
        int rt=solve(r->right, ans);
        
        ans += (abs(lt) + abs(rt));
        
        return (r->data + (lt+rt) -1);
    }
};