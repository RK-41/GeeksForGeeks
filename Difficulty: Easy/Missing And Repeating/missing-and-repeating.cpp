class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        // 10.12.25 potd
        int n=arr.size(), a=-1, b=-1, val;
        
        for(int i=0; i<n; i++){
            val = (arr[i]-1)%n;
            arr[val] += n;
        }
        
        for(int i=0; i<n; i++){
            val = (arr[i]-1)/n;
            if(val >= 2)    a = i+1;
            else if(val == 0)   b = i+1;
        }
        
        return {a,b};
    }
};