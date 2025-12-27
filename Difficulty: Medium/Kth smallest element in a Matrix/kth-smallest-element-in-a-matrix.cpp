class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        // 31.05.25 POTD
        // 27.12.25 (POTD)
        priority_queue<int> pq;
        
        for(auto r: matrix){
            for(auto c: r){
                pq.push(c);
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }
        
        return pq.top();
    }
};