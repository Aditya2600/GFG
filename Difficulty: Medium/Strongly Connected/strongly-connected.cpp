//Position this line where user code will be pasted.
class Solution {
  public:
    void dfsFill(int u, vector<vector<int>> &adj, stack<int>& st, vector<bool>& vis){
        vis[u] = true;
        
        for(auto &x : adj[u]){
            if(!vis[x]){
                dfsFill(x, adj, st, vis);
            }
        }
        st.push(u);
    }
    
    void dfsTraversal(int x, vector<vector<int>>& revAdj, vector<bool>& vis){
        vis[x] = true;
        
        for(auto &u : revAdj[x]){
            if(!vis[u]){
                dfsTraversal(u, revAdj, vis);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        stack<int> st;
        int v = adj.size();
        vector<bool> vis(v, false);
        
        for(int i=0; i<v; i++){
            if(vis[i] == false){
                dfsFill(i, adj, st, vis);
            }
        }
        vector<vector<int>> revAdj(v);
        for(int i=0; i<v; i++){
            for(auto &x : adj[i]){
                revAdj[x].push_back(i);
            }
        }
        int countScc = 0;
        vis = vector<bool>(v, false);
        
        while(!st.empty()){
             int node = st.top();
             st.pop();
             
             if(!vis[node]){
                 dfsTraversal(node, revAdj, vis);
                 countScc++;
             }
        }
        return countScc;
    }
};