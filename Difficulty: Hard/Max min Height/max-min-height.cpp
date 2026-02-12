class Solution {
  public:
    int maxMinHeight(vector<int> &arr, int k, int w) {
        // code here
        // 12.02.26 potd
        long long int ans=-1;
        long long int minH = *min_element(arr.begin(), arr.end());
        long long int maxH = INT_MAX/2;
        
        while(minH <= maxH){
            int guessH = (minH + maxH) / 2;
            if(isOK(arr, k, w, guessH) == true){
                ans = guessH;
                minH = guessH + 1;
            } else {
                maxH = guessH - 1;
            }
        }
        
        return ans;
    }
    
    bool isOK(vector<int> &arr, int days, int cs, long long int h){
        int n = arr.size();
        vector<long long> waterSupply(n, 0);
        
        if(arr[0] < h){
            waterSupply[0] = h-arr[0];
            days -= (h-arr[0]);
        }
        
        if(days < 0){
            return false;
        }
        
        for(int i=1; i<n; i++){
            waterSupply[i] = waterSupply[i-1];
            int actualH = arr[i];
            if(i >= cs){
                actualH += (waterSupply[i] - waterSupply[i-cs]);
            } else {
                actualH += waterSupply[i];
            }
            
            if(actualH < h){
                waterSupply[i] += (h - actualH);
                days -= (h - actualH);
            }
            
            if(days < 0){
                return false;
            }
        }
        
        return true;
    }
};