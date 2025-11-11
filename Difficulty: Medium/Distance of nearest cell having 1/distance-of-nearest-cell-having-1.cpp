class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        int dr[] = {1, 0, -1, 0};
        int dc[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int> (m,0));
        vector<vector<int>> res(n, vector<int> (m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int d = q.front().second;
            q.pop();
            res[r][c] = d;
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr >= n || nc < 0 || nc >= m || vis[nr][nc] == 1){
                    continue;
                }
                else{
                    vis[nr][nc] = 1;
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        return res;
    }
};