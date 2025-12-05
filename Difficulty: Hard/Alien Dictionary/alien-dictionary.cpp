class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n = words.size();
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;
        
        for(auto &w : words){
            for(char c : w){
                if(!indegree.count(c)) indegree[c] = 0;
            }
        }
        for(int i=0; i<n-1; i++){
            string s1 = words[i];
            string s2 = words[i+1];
            int len1 = s1.size(), len2 = s2.size();
            int len = min(len1, len2);
            int j = 0;
            while(j < len && s1[j] == s2[j]){
                j++;
            }
            if(j < len){
                adj[s1[j]].push_back(s2[j]);
                indegree[s2[j]]++;
            }
            else{
                if(len1 > len2) return "";
            }
        }
        queue<char> q;
        for(auto &p : indegree){
            if(p.second == 0) q.push(p.first);
        }
        string order;
        while(!q.empty()){
            char node = q.front();
            q.pop();
            order.push_back(node);
            
            for(char nxt : adj[node]){
                indegree[nxt]--;
                if(indegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }
        if(order.size() == indegree.size()) return order;
        return "";
    }
};