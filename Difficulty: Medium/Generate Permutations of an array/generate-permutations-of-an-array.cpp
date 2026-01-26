class Solution {
  public:
    vector<vector<int>> permuteDist(vector<int>& arr) {
        // code here
        // 26.01.26 potd
        vector<vector<int>> ans;
        backtrack(arr, 0, ans);
        
        return ans;
    }
    
    void backtrack(vector<int>& arr, int idx, vector<vector<int>>& ans) {
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }
        
        for(int i=idx; i<arr.size(); i++){
            swap(arr[idx], arr[i]);
            backtrack(arr, idx+1, ans);
            swap(arr[idx], arr[i]);
        }
    }
};