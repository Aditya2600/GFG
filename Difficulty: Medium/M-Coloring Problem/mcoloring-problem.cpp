class Solution {
  public:
    
    bool isSafe(int v, int color, vector<vector<int>> &adj, vector<int>& col){
        for(int u : adj[v]){
            if(col[u] == color){
                return false;
            }
        }
        return true;
    }
    
    bool dfs(int v, vector<vector<int>> &edges, int m, vector<int>& col){
        int n = edges.size();
        if(v == n) return true;
        
        for(int c = 1; c<=m; c++){
            if(isSafe(v, c, edges, col)){
                col[v] = c;
                if(dfs(v+1, edges, m, col)) return true;
                col[v] = 0;
            }
        }
        return false;
    }
    
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        int n = edges.size();
        vector<vector<int>> adj(v);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> col(n, 0);
        if(dfs(0, adj, m, col)) return true;
        return false;
    }
};