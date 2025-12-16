// User function Template for C++
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int findUPar(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x] = findUPar(parent[x]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        
        if(ulp_u == ulp_v){
            return;
        }
        
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    bool isValid(int adjr, int adjc, int n, int m){
        return adjr >= 0 && adjr < n && adjc < m && adjc >= 0;
    }
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        
        parent.resize(n*m);
        rank.resize(n*m, 0);
        
        for(int i=0; i<n*m; i++){
            parent[i] = i;
        }
        
        int vis[n][m];
        memset(vis, 0, sizeof vis);
        
        int cnt = 0;
        vector<int> ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            vis[row][col] = 1;
            cnt++;
            
            int dr[] = {-1, 0, +1, 0};
            int dc[] = {0, +1, 0, -1};
            
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if(isValid(nr, nc, n, m)){
                    if(vis[nr][nc] == 1){
                        int nodeNo = row * m + col;
                        int adjNodeNo = nr * m + nc;
                        if(findUPar(nodeNo) != findUPar(adjNodeNo)){
                            cnt--;
                            unionByRank(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
