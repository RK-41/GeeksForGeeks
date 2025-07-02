//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
        // 03.07.25 (potd)
        
        int i=0, ans=-1;
        unordered_map<char,int> um;
        
        for(int j=0; j<s.size(); j++){
            um[s[j]]++;
            while(um.size()>k){
                um[s[i]]--;
                if(um[s[i]]==0)
                    um.erase(s[i]);
                i++;
            }
            if(um.size()==k)
                ans=max(ans,j-i+1);
        }
        
        return ans;
    }
};
