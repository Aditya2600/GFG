#include <vector>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());

        priority_queue<tuple<int, int, int>> maxHeap;
        set<pair<int, int>> seen;

        maxHeap.push(make_tuple(a[0] + b[0], 0, 0));
        seen.insert({0, 0});

        vector<int> result;

        while (k-- && !maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int sum = get<0>(top);
            int i = get<1>(top);
            int j = get<2>(top);
            result.push_back(sum);

            if (i + 1 < n && seen.find({i + 1, j}) == seen.end()) {
                maxHeap.push(make_tuple(a[i + 1] + b[j], i + 1, j));
                seen.insert({i + 1, j});
            }

            if (j + 1 < n && seen.find({i, j + 1}) == seen.end()) {
                maxHeap.push(make_tuple(a[i] + b[j + 1], i, j + 1));
                seen.insert({i, j + 1});
            }
        }

        return result;
    }
};