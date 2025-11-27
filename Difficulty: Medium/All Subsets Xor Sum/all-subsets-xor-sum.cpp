class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        // 27.11.25 potd
        int OR =0 , n = arr.size();
        for(int x : arr) OR |= x;
        
        return OR * (pow(2,n-1)); 
    }
};