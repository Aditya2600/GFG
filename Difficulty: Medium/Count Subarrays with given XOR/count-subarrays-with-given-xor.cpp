// class Solution {
//   public:
//     long subarrayXor(vector<int> &arr, int k) {
//         // code here
        
//         int n = arr.size();
//         int cnt = 0;
//         for(int i=0; i<n; i++){
//             int ans = 0;
//             for(int j=i; j<n; j++){
//                 ans ^= arr[j];
//                 if(ans == k) cnt++;
//             }
//         }
//         return cnt;
//     }
// };
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        int n = arr.size();
        int cnt = 0;
        unordered_map<int, int> mp;
        mp.insert({0, 1});
        int xr = 0;
        for(int i=0; i<n; i++){
            xr ^= arr[i];
            int x = xr ^ k;
            if(mp.find(x) != mp.end()){
                cnt += mp[x];
            }
            mp[xr]++;
        }
        return cnt;
    }
};