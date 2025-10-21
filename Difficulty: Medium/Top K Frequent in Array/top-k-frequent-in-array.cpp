class Solution {
  public:
    vector<int> topKFreq(vector<int>& nums, int k) {
        // Code here
        // 21.10.25 (POTD)
        
        vector<int> ans;
        unordered_map<int,int> um;
        priority_queue<pair<int,int>> q;
        
        for(auto n: nums)
            um[n]++;
        
        for(auto u: um)
            q.push(pair<int,int>(u.second,u.first));
            
        while(k--){
            // int c=q.top().first;
            int d=q.top().second;
            q.pop();
            
            ans.push_back(d);
        }
        
        return ans;
    }
};
