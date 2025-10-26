class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        // 26.10.25 (POTD)
        int ans=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto a: arr){
            pq.push(a);
        }
        
        while(pq.size() >= 2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            
            a += b;
            ans += a;
            pq.push(a);
        }
        
        return ans;
    }
};