class Solution {
  public:
    bool isValid(int r, int c, vector<vector<int>>& maze){
        int n = maze.size();
        if(r >=0 && r < n && c >= 0 && c < n){
            return true;
        }
        return false;
    }
    void dfs(int r, int c, vector<vector<int>>& maze, vector<vector<bool>>& vis, vector<string> &ans, string& path){
        int n = maze.size();
        if(r == n-1 && c == n-1){
            ans.push_back(path);
            return;
        }
        int row[4] = {0, +1, 0, -1};
        int col[4] = {+1, 0, -1, 0};
        char mv[4] = {'R', 'D', 'L', 'U'};
        
        for(int i=0; i<4; i++){
                int nr = r + row[i];
                int nc = c + col[i];
                if(isValid(nr, nc, maze) && maze[nr][nc] == 1 && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    path.push_back(mv[i]);
                    dfs(nr, nc, maze, vis, ans, path);
                    path.pop_back();
                    vis[nr][nc] = false;
                }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        string path;
        vector<vector<bool>> vis(n, vector<bool> (n,false));
        vis[0][0] = true;
        dfs(0, 0, maze, vis, ans, path);
        sort(ans.begin(), ans.end());
        return ans;
    }
};