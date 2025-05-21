class Solution {
  public:
    int kthSmallest(int m, int n, int k) {
        // code here
        // 21.05.25 potd
        int low=1, high=m*n;
        
        while(low < high){
            int mid = (low + high) / 2;
            int count = countElementLessThanMid(mid, m, n);
            if(count < k)   low = mid + 1;
            else        high = mid;
        }
        
        return low;
    }
    
    int countElementLessThanMid(int &mid, int m, int n){
        int col=0, row=m-1, count=0;
        
        while(col<n && row>=0){
            if((row+1) * (col+1) <= mid){
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        
        return count;
    }
};
