//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        // 30.01.25 potd
        vector<vector<int>> solutions; // Stores all valid solutions
        vector<int> queenPositions(n, 0); // Stores the row positions of queens in each column
        
        backtrack(0, n, queenPositions, solutions); // Start solving from column 0
        
        return solutions; // Return all valid solutions
    }
    
  private:
    void backtrack(int currentColumn, int n, vector<int>& queenPositions, vector<vector<int>>& solutions) {
        // Base case: If all columns are filled, add the current configuration to solutions
        if (currentColumn == n) {
            solutions.push_back(queenPositions);
            return;
        }
        
        // Try placing a queen in each row of the current column
        for (int currentRow = 0; currentRow < n; currentRow++) {
            // Check if it's safe to place a queen at (currentRow, currentColumn)
            if (isPositionSafe(queenPositions, currentColumn, currentRow)) {
                queenPositions[currentColumn] = currentRow + 1; // Place the queen (1-indexed)
                backtrack(currentColumn + 1, n, queenPositions, solutions); // Recur for the next column
            }
        }
    }
    
    bool isPositionSafe(vector<int>& queenPositions, int column, int row) {
        // Check all previous columns
        for (int prevColumn = 0; prevColumn < column; prevColumn++) {
            int queenRow = queenPositions[prevColumn] - 1; // Get the row of the queen in prevColumn (0-indexed)
            
            // Check if the new queen is in the same row or on the same diagonal
            if (queenRow == row || abs(queenRow - row) == abs(prevColumn - column)) {
                return false; // Not safe
            }
        }
        
        return true; // Safe to place the queen
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends