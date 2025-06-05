class Solution {
  public:
        // Code here
        int dfs(int node, int dest, vector<vector<int>>& adj, vector<int>& memo) {
        if (node == dest) return 1;
        if (memo[node] != -1) return memo[node];

        int count = 0;
        for (int neighbor : adj[node]) {
            count += dfs(neighbor, dest, adj, memo);
        }

        memo[node] = count;
        return count;
    }

    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        vector<int> memo(V, -1);
        return dfs(src, dest, adj, memo);
    }
};