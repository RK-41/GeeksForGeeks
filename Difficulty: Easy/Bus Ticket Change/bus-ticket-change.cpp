class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        // 13.01.26 POTD
        if(arr[0] > 5)
            return false;
        
        int curr = 0;
        unordered_map<int,int> um;
        for(auto a: arr){
            um[a]++;
            int req = a-5;
            if(req > curr)
                return false;
            
            while(req > 0){
                if(req >= 10 && um[10] > 0){
                    req -= 10;
                    um[10]--;
                } else if(um[5] > 0){
                    req -= 5;
                    um[5]--;
                } else {
                    return false;
                }
            }
            
            curr += 5;
        }
        
        return true;
    }
};