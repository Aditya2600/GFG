class Solution {
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int cc = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 'W'){
                    continue;
                }
                cc++;
                grid[i][j] = 'W';
                queue<pair<int, int>> qu;
                qu.push({i, j});
                while(!qu.empty()){
                    auto curr = qu.front();
                    qu.pop();
                    int currRow = curr.first;
                    int currCol = curr.second;
                    if(currRow - 1 >= 0 && grid[currRow - 1][currCol] == 'L'){
                        qu.push({currRow - 1, currCol});
                        grid[currRow - 1][currCol] = 'W';
                    }
                    if(currCol - 1 >= 0 && grid[currRow][currCol - 1] == 'L'){
                        qu.push({currRow, currCol - 1});
                        grid[currRow][currCol - 1] = 'W';
                    }
                    if(currRow + 1 < n && grid[currRow + 1][currCol] == 'L'){
                        qu.push({currRow + 1, currCol});
                        grid[currRow + 1][currCol] = 'W';
                    }
                    if(currCol + 1 < m && grid[currRow][currCol + 1] == 'L'){
                        qu.push({currRow, currCol + 1});
                        grid[currRow][currCol + 1] = 'W';
                    }
                    if(currRow - 1 >= 0 && currCol - 1 >= 0 && grid[currRow - 1][currCol - 1] == 'L'){
                        qu.push({currRow - 1, currCol - 1});
                        grid[currRow - 1][currCol - 1] = 'W';
                    }
                    if(currCol - 1 >= 0 && currRow + 1 < n && grid[currRow + 1][currCol - 1] == 'L'){
                        qu.push({currRow + 1, currCol - 1});
                        grid[currRow + 1][currCol - 1] = 'W';
                    }
                    if(currRow + 1 < n && currCol + 1 < m && grid[currRow + 1][currCol + 1] == 'L'){
                        qu.push({currRow + 1, currCol + 1});
                        grid[currRow + 1][currCol + 1] = 'W';
                    }
                    if(currCol + 1 < m && currRow - 1 >= 0 && grid[currRow - 1][currCol + 1] == 'L'){
                        qu.push({currRow - 1, currCol + 1});
                        grid[currRow - 1][currCol + 1] = 'W';
                    }
                }
            }
        }
        return cc;
    }
};