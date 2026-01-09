class Solution {
  public:
    // 04.07.25 potd
    // 09.01.26 (potd)
    int countAtMostK(vector<int> &arr, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        
        int i =0;
        
        for(int j = 0;j < arr.size();j++){
            mp[arr[j]]++;
            
            while(mp.size() > k){
                mp[arr[i]]--;
                
                if(mp[arr[i]] == 0){
                    mp.erase(arr[i]);
                }
                
                i++;
            }
            
            ans += j-i+1;
        }
        
        return ans;
    }
};