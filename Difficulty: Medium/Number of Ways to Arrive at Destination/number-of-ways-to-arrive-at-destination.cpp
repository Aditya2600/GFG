//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
int countPaths(int n, vector<vector<int>>& roads) {
    // Create adjacency list: {adjacent_node, weight}
    vector<pair<int, int>> adj[n];
    for(auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    
    // Priority queue of {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    vector<long long> dist(n, LLONG_MAX);  // Distance array
    vector<int> ways(n, 0);               // Number of ways to reach each node
    
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0});  // {distance, node}
    
    while(!pq.empty()) {
        long long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        // If we found a longer path, skip
        if(dis > dist[node]) continue;
        
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edjW = it.second;
            
            // Found a shorter path
            if(dis + edjW < dist[adjNode]) {
                dist[adjNode] = dis + edjW;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node];
            }
            // Found another path with same length
            else if(dis + edjW == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % 1000000007;
            }
        }
    }
    
    return ways[n-1];
}
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}
// } Driver Code Ends