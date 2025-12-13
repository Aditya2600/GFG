class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        int n = dist.size();
        int INF = 100000000; // given in the input

        for(int via = 0; via < n; via++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    
                    // Only add if both edges are valid
                    if (dist[i][via] != INF && dist[via][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }
};