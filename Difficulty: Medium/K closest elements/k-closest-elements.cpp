class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        // Code here
        // 12.06.25 (potd)
        map<int,vector<int>> mp;
        int n = arr.size();
        for(auto it:arr){
            mp[abs(it-x)].push_back(it);
        }
        vector<int> ans;
        for(auto it:mp){
            if(it.first==0){
                continue;
            }
            if(k==0){
                break;
            }
            sort(it.second.rbegin(),it.second.rend());
            for(auto num:it.second){
                ans.push_back(num);
                k--;
                if(k==0){
                    break;
                }
            }
        }
        return ans;
    }
};