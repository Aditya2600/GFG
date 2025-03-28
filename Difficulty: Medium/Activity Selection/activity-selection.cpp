//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        // code here
 int n = start.size();
    vector<pair<int, int>> activities;

    // Store (finish time, start time) pairs
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }

    // Step 1: Sort activities by finish time
    sort(activities.begin(), activities.end());

    int count = 1;  // Always select the first activity
    int last_finish_time = activities[0].first;

    // Step 2: Iterate through activities
    for (int i = 1; i < n; i++) {
        // Correct condition: Start time of current activity must be > last selected finish time
        if (activities[i].second > last_finish_time) {
            count++;
            last_finish_time = activities[i].first;  // Update last finish time
        }
    }

    return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends