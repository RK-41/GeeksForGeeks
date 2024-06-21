//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {
        // Code here
        // 21.06.24 POTD
        int i=0, j=0, n=str.size();
        int commaPos;
        double arr[4];
        
        for(; i<n; i++){
            if(str[i] == '/' || str[i] == ' '){
                j++;
                continue;
            }
            
            if(str[i] != ','){
                arr[j] = arr[j]*10 + str[i] - '0';
            } else {
                commaPos = i;
            }
        }
        
        double f1 = arr[0]/arr[1];
        double f2 = arr[2]/arr[3];
        
        if(f1 > f2){
            return str.substr(0,commaPos);
        } else if(f2 > f1){
            return str.substr(commaPos+2);
        }
        
        return "equal";
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends