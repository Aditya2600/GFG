/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  // Helper function to return pair of sums
pair<int, int> solve(Node* root) {
// if node is null, return 0 for both include and exclude
    if (!root) return {0, 0};
// solve for left child
    auto left = solve(root->left);
// solve for right child
    auto right = solve(root->right);
// include current node: add node value + exclude from left + exclude from right
    int include = root->data + left.second + right.second;
// exclude current node: take max of include/exclude from left and right
    int exclude = max(left.first, left.second) + max(right.first, right.second);
// return pair of include and exclude
    return {include, exclude};
}

int getMaxSum(Node *root) {
// call helper and get result for root
    auto res = solve(root);
// return max of include and exclude for root
    return max(res.first, res.second);
}
};