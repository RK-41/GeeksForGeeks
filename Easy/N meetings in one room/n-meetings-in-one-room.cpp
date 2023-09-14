//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // PROBLEM: OVERLAPPING INTERVALS
        
        int delCnt=0;
        vector<pair<int,int>> meetings(n);
        
        for(int i=0; i<n; i++){
            meetings[i].first = start[i];
            meetings[i].second = end[i];
        }
        
        sort(meetings.begin(), meetings.end());
        auto prev = meetings[0];
        
        for(int i=1; i<n; i++){
            if(meetings[i].first <= prev.second){
                delCnt++;
                
                if(meetings[i].second <= prev.second){
                    prev = meetings[i];
                }
            }
            else{
                prev = meetings[i];
            }
        }
        
        return n-delCnt;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends