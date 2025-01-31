//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

#define vi vector<int>
#define vvi vector<vi>

class Solution {
  public: 
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        // 31.01.25 potd
        solve(mat);
    }
    
    // Function to check if placing 'op' at (r,c) is valid
    bool isValid(int r, int c, int op, vvi &mat){
        // checking for row
        for(int j=0; j<mat.size(); j++){
            if(mat[r][j] == op) return false;
        }
        
        // checking for col
        for(int i=0; i<mat.size(); i++){
            if(mat[i][c] == op) return false;
        }
        
        // checking for 3x3 sub-grid
        int rc = (r/3) * 3, cc = (c/3) * 3;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(mat[rc+i][cc+j] == op)   return false;
            }
        }
        
        // the number is valid in this position
        return true;
    }
    
    // Funciton to solve the Sudoku using backtracking
    bool solve(vvi &mat){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                // if an emplty cell (0) is found
                if(mat[i][j] == 0){
                    // try placing numbers 1 to 9
                    for(int op=1; op<10; op++){
                        // checking if the number is valid
                        if(isValid(i, j, op, mat)){
                            // placing the number
                            mat[i][j] = op;
                            
                            // recursively solve next emplty cell
                            if(solve(mat))
                                return true;
                                
                            // backtrack if placing 'op' leads to no solution
                            mat[i][j] = 0;
                        }
                    }
                    
                    // if no number can be placed
                    return false;
                }
            }
        }
        
        // Sudoku solved successfully
        return true;
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends