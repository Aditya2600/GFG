// User function Template for C++

class Solution {
  public:
  
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis, vector<pair<int, int>>& vec, int row0, int col0){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = true;
        vec.push_back({row - row0, col - col0});
        
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for(int i=0; i<4; i++){
            int nr = row + dr[i];
            int nc = col + dc[i];
            
            if(nr >= 0 && nc >= 0 && nr < n && nc < m && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, grid, vis, vec, row0, col0);
            }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> vis(n, vector<bool> (m, false));
        set<vector<pair<int, int>>> st;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
