//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            int s = arr[i][0];
            int e = arr[i][1];
            if(!ans.empty() && ans.back()[1] >= e){
                continue;
            }
            for(int j = i+1; j<n; j++){
                if(arr[j][0] <= e){
                    e = max(e, arr[j][1]);
                }
                else break;
            }
            ans.push_back({s, e});
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends