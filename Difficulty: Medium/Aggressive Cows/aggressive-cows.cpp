// class Solution {
//   public:
//     bool canWePlace(int dist, vector<int> &stalls, int k){
//         int cntCows = 1;
//         int lastCow = stalls[0];
//         int n = stalls.size();
//         for(int i=1; i<n; i++){
//             if(stalls[i] - lastCow >= dist){
//                 cntCows++;
//                 lastCow = stalls[i];
//             }
//             if(cntCows >= k){
//                 return true;
//             }
//         }
//         return false;
//     }
//     int aggressiveCows(vector<int> &stalls, int k) {
//         // code here
//         sort(stalls.begin(), stalls.end());
//         int n = stalls.size();
//         int mx = INT_MIN;
//         int mn = INT_MAX;
//         for(int i=0; i<n; i++){
//             mx = max(mx, stalls[i]);
//             mn = min(mn, stalls[i]);
//         }
//         for(int i=1; i<=(mx - mn); i++){
//             if(canWePlace(i, stalls, k)){
//                 continue;
//             }
//             else return i-1;
//         }
//         return -1;
//     }
// };

class Solution {
  public:
    bool canWePlace(int dist, vector<int> &stalls, int k){
        int cntCows = 1;
        int lastCow = stalls[0];
        int n = stalls.size();
        for(int i=1; i<n; i++){
            if(stalls[i] - lastCow >= dist){
                cntCows++;
                lastCow = stalls[i];
            }
            if(cntCows >= k){
                return true;
            }
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int mx = stalls[n-1];
        int mn = stalls[0];
        int lo = 0;
        int hi = mx - mn;
        while(lo <= hi){
            int mid = (lo + hi) >> 1;
            if(canWePlace(mid, stalls, k)){
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
            }
        }
        return hi;
    }
};