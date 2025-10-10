//User function Template for C++
/*Structure of the node of the binary tree is as
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
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	// 10.10.25 (POTD)
    	if(root==NULL)  return {};
    	
    	vector<int> ans;
    	vector<vector<int>> v;
    	queue<Node*> q;
    	bool ltr=0;
    	
    	q.push(root);
    
    	while(!q.empty()){
    	    int sz=q.size();
    	    vector<int> level(sz);
    	    
    	    for(int i=0; i<sz; i++){
    	        Node* f=q.front();
    	        q.pop();
    	        
    	        int idx=ltr?sz-i-1:i;
    	        level[idx]=f->data;
    	        
    	        if(f->left) q.push(f->left);
    	        if(f->right)    q.push(f->right);
    	    }
    	    
    	    ltr=!ltr;
    	    v.push_back(level);
    	}
    	
    	for(int i=0; i<v.size(); i++)
    	    for(int j=0; j<v[i].size(); j++)
    	        ans.push_back(v[i][j]);
    	        
    	return ans;
    }
};

