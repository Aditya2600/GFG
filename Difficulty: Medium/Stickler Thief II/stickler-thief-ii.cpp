//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  int robHelper(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        int prev2 = nums[n-1];
        int prev1 = max(nums[n-1],nums[n-2]);
        for(int i=n-3; i>=0; i--){
            int curr = max(prev2 + nums[i], 0 + prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    int maxValue(vector<int>& arr) {
        // your code here
        vector<int> temp1,temp2;
       int n = arr.size();
       if(n == 1)return arr[0];
       for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(arr[i]);
        if(i!=n-1) temp2.push_back(arr[i]);
       }
       return max(robHelper(temp1),robHelper(temp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends