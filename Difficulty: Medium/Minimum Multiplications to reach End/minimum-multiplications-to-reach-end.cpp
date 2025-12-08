// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        if(start == end) return 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dis(100000, 1e9);
        int mod = 1e5;
        dis[start] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();
            for(int it : arr){
                int num = (node * it) % mod;
                if(dis[num] > steps + 1){
                    dis[num] = steps + 1;
                    if(num == end) return steps + 1;
                    q.push({num, steps + 1});
                }
            }
        }
        return -1;
    }
};
