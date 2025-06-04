// User function Template for C++

class Solution {
  public:
  vector<vector<char>> grid;
    vector<vector<int>> result;
    bool canPlaceQueen(int row, int col, int n){
        for(int i=row-1; i>=0; i--){
            if(grid[i][col] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col-1; i>=0 and j>=0; i--, j--){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 and j<n; i--, j++){
            if(grid[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void f(int row, int n){
        if(row == n){
            vector<int> temp(n, -1);
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(grid[i][j] == 'Q'){
                        temp[j] = i+1;
                    }
                }
            }
            result.push_back(temp);
            return;
        }
        for(int col=0; col<n; col++){
            if(canPlaceQueen(row, col, n)){
                grid[row][col] = 'Q';
                f(row+1, n);
                grid[row][col] = '.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        grid.resize(n, vector<char> (n, '.'));
        f(0, n);
        return result;
    }
};