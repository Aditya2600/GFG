//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        int total_gas = 0, total_cost = 0;
    int current_gas = 0, start_index = 0;

    for (int i = 0; i < gas.size(); i++) {
        total_gas += gas[i];
        total_cost += cost[i];
        
        current_gas += gas[i] - cost[i];

        // If current gas is negative, we cannot start from this or any previous station
        if (current_gas < 0) {
            start_index = i + 1;  // Try starting from the next station
            current_gas = 0;      // Reset current gas
        }
    }

    return (total_gas >= total_cost) ? start_index : -1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends