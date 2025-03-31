//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends


class DisjointSet {
    vector<int> parent, rank, size;
    public:
        DisjointSet(int n){
            parent.resize(n+1);
            rank.resize(n+1, 0);
            size.resize(n+1, 1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
        
        int findUPar(int node){
            if(node == parent[node]) return node;
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank(int v, int u){
            int up_u = findUPar(u);
            int up_v = findUPar(v);
            if(up_u == up_v) return;
            if(rank[up_u] < rank[up_v]){
                parent[up_u] = up_v;
            }
            else if(rank[up_u] > rank[up_v]){
                parent[up_v] = up_u;
            }
            else{
                parent[up_v] = up_u;
                rank[up_u]++;
            }
        }
        
        void unionBySize(int v, int u){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
             }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
  public:
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        DisjointSet ds(v);
        for(auto& e : edges){
            ds.unionBySize(e[0], e[1]);
        }
        unordered_map<int, vector<int>> components;
        for(int i=0; i<v; i++){
            int leader = ds.findUPar(i);
            components[leader].push_back(i);
        }
        vector<vector<int>> results;
        for(auto &it : components){
            results.push_back(it.second);
        }
        return results;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends