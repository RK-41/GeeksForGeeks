class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        // 09.09.25 potd
        sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int maxi=INT_MIN;
        for(int i=0;i<mices.size();i++) {
            maxi=max(maxi,abs(holes[i]-mices[i]));
        }
        return maxi;
    }
};

