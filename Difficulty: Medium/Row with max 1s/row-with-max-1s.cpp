// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        // 22.12.25 (POTD)
        int n=arr.size(), m=arr[0].size();
        int ans=-1, i=0, j=m-1;
        
        while(i<n && j>=0){
            if(arr[i][j] == 1){
                j--;
                ans = i;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};