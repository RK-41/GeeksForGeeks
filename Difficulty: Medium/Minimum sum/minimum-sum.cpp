// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        // 23.06.25 (POTD)
        if(arr.size() == 2){
            return to_string(arr[0] + arr[1]);
        }
        
        string ans;
        int carry = 0, i = 9;
        unordered_map<int,int> um;

        for(auto a: arr){
            if(a != 0)
                um[a]++;
        }
        
        while(i>0){
            if(um[i] == 0){
                i--;
                continue;
            }
            
            int a = i + carry;
            um[i]--;
            
            while(i>0){
                if(um[i] > 0){
                    a += i;
                    um[i]--;
                    break;
                }
                i--;
            }
            
            carry = a > 9 ? 1 : 0;
            a %= 10;
            ans.push_back(a+'0');
        }
        
        if(carry)   ans = "1" + ans;
        reverse(ans.begin(), ans.end());
            
        return ans;
    }
};
