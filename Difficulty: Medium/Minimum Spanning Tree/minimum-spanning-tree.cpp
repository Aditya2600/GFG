// class Solution {
//   public:
//   typedef pair<int, int> p;
//     int spanningTree(int V, vector<vector<int>>& edges) {
//         // code here
//         unordered_map<int, vector<pair<int, int>>> adj;
//         int e = edges.size();
//         for(int i=0; i<e; i++){
//             int u = edges[i][0];
//             int v = edges[i][1];
//             int w = edges[i][2];
//             adj[u].push_back({v, w});
//             adj[v].push_back({u, w});
//         }
//         priority_queue<p, vector<p>, greater<p>> pq;
//         pq.push({0, 0});
//         vector<bool> inMST(V, false);
//         int sum = 0;
//         while(!pq.empty()){
//             int wt = pq.top().first;
//             int node = pq.top().second;
//             pq.pop();
            
//             if(inMST[node] == true){
//                 continue;
//             }
//             inMST[node] = true;
//             sum += wt;
            
//             for(auto it : adj[node]){
//                 int adjNode = it.first;
//                 int adjNodeWt = it.second;
                
//                 if(!inMST[adjNode]){
//                     pq.push({adjNodeWt, adjNode});
//                 }
//             }
//         }
//         return sum;
//     }
// };
class Solution {
  public:
    vector<int> parent;
    vector<int> rank;
    
    int find(int x){
        if(parent[x] == x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    
    void Union(int x, int y){
        int x_parent = find(x);
        int y_parent = find(y);
        
        if(x_parent == y_parent){
            return;
        }
        
        if(rank[x_parent] > rank[y_parent]){
            parent[y_parent] = x_parent;
        }
        else if(rank[x_parent] < rank[y_parent]){
            parent[x_parent] = y_parent;
        }
        else{
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int Kruskal(vector<vector<int>>& vec){
        int sum = 0;
        for(auto &temp : vec){
            int u = temp[0];
            int v = temp[1];
            int wt = temp[2];
            
            int parent_u = find(u);
            int parent_v = find(v);
            
            if(parent_u != parent_v){
                Union(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    
    
  
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        parent.resize(V);
        rank.resize(V, 0);
        for(int i=0; i<V; i++){
            parent[i] = i;
        }
       sort(edges.begin(), edges.end(), [&](vector<int> &vec1, vector<int> &vec2) {
           return vec1[2] < vec2[2];
       });
       return Kruskal(edges);
    }
};