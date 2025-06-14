/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
 bool isMirror(Node* left, Node* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;

        return (left->data == right->data) &&
               isMirror(left->left, right->right) &&
               isMirror(left->right, right->left);
    }
class Solution {
  public:
    bool isSymmetric(Node* root) {
        // Code here
        if (!root) return true; // An empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};