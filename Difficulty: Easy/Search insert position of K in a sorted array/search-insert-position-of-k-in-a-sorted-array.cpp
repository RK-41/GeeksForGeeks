class Solution {
  public:
    int searchInsertK(vector<int> &Arr, int k) {
        // code here
        // 20.12.25 (potd)
        int N = Arr.size();
        if(k>Arr[N-1])  return N;
        for(int i=0; i<N; i++){
            if(Arr[i]==k || Arr[i]>k)
                return i;
        }
        // return N;
    }
};