class Solution {
  public:
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int n = mat.size();
        int m = mat[0].size();
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> idx(n, 0);
        for(int i=0; i<n; i++){
            pq.push({mat[i][0], i});
            idx[i] = 1;
        }
        vector<int> ans;
        while(!pq.empty()){
            auto [val, r] = pq.top();
            pq.pop();
            ans.push_back(val);
            
            if(idx[r] < mat[r].size()){
                pq.push({mat[r][idx[r]], r});
                idx[r]++;
            }
        }
        return ans;
    }
};