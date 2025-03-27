//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();  // Get the size of the arrays

        // Step 1: Sort both arrival and departure arrays
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int platforms_needed = 0, max_platforms = 0;
        int i = 0, j = 0;

        // Step 2: Use two-pointer approach
        while (i < n && j < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++; // A train arrives
                i++;
            } else {
                platforms_needed--; // A train departs
                j++;
            }
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends