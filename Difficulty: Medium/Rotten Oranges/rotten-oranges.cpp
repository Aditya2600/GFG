class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 2){
                    vis[i][j] = 2;
                    q.push({{i, j}, 0});
                }
                else vis[i][j] = 0;
            }
        }
        int tm = 0;
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, +1, 0, -1};
        while(!q.empty()){
            auto curr = q.front();
            int r = curr.first.first;
            int c = curr.first.second;
            int t = curr.second;
            tm = max(tm, t);
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + drow[i];
                int nc = c + dcol[i];
                if(nr < n && nr >= 0 && nc >= 0 && nc < m && mat[nr][nc] == 1 && vis[nr][nc] != 2){
                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 2;
                }
            }
        }
        for(int i=0 ; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] != 2 && mat[i][j] == 1) return -1;
            }
        }
        return tm;
    }
};