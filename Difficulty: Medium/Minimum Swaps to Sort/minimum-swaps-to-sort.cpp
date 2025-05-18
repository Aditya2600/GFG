//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int>& arr) {
        // Code here
        int n = arr.size();
        vector<pair<int, int>> Vec(n);
        for(int i=0; i<n; i++){
            Vec[i] = {arr[i], i};
        }
        sort(Vec.begin(), Vec.end());
        int swaps = 0;
        for(int i=0; i<n; i++){
            if(Vec[i].second == i) continue;
            else{
                swaps++;
                swap(Vec[i], Vec[Vec[i].second]);
                --i;
            }
        }
        return swaps;
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minSwaps(arr) << endl;
    }
}

// } Driver Code Ends