class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
        // 22.10.25 potd
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size(), idx = 0;
        
        for(int i=0; i<=k; i++){
            pq.push(arr[i]);
        }
        
        for(int i=k+1; i<n; i++){
            arr[idx++] = pq.top();
            pq.pop();
            pq.push(arr[i]);
        }
        
        while(pq.size()){
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};