// User function Template for C++

class Solution {
  public:
    string removeKdig(string S, int K) {
        // 19.01.26 (potd)
        if(K >= S.size())
            return "0";
            
        string ans;
        for(int i=0; i<S.size(); i++){
            while(ans.size()>0 && K>0 && ans.back()>S[i]){
                ans.pop_back();
                K--;
            }
            
            ans+=S[i];
        }
            
        while(K>0 && ans.size()>0){
            ans.pop_back();
            K--;
        }
        
        int i=0;
        while(ans[i]=='0' && i<ans.size()){
            i++;
        }
        
        if(i==ans.size())
            return "0";
            
        return ans.substr(i);
    }
};
