class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        // 27.05.25 (POTD)
        vector<int> ans;
        stack<int> st;
        int N = preorder.size();
        
        for(int i=0, j=1; j<N; i++,j++){
            bool found=false;
            
            if(preorder[i]>preorder[j])   
                st.push(preorder[i]);
            else{
                while(!st.empty()){
                    if(preorder[j]>st.top()){
                        st.pop();
                        found=true;
                    }
                    else
                        break;
                }
            }
            
            if(found)
                ans.push_back(preorder[i]);
        }
        
        ans.push_back(preorder[N-1]);
        return ans;
    }
};