class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        // code here
        // 13.07.25 (potd)
        int n = arr.size();
        vector<int> lis;
        int sum=0, lisSum[n+1];
        lisSum[0]=0;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            int idx=lower_bound(lis.begin(),lis.end(),arr[i])-lis.begin();
            if(idx==lis.size())
                lis.push_back(arr[i]);
            else
                lis[idx]=arr[i];
            
            lisSum[idx+1]=lisSum[idx]+arr[i];
        }
        
        return sum-lisSum[lis.size()];
    }
};