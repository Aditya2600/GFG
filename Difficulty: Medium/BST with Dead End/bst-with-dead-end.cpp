/*The Node structure is
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};*/

class Solution {
  public:
   bool isDeadEndUtil(Node* node, int minVal, int maxVal) {
        if (!node) return false;
        
        if (minVal == maxVal) return true;
        
        return isDeadEndUtil(node->left, minVal, node->data - 1) ||
               isDeadEndUtil(node->right, node->data + 1, maxVal);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        return isDeadEndUtil(root, 1, INT_MAX);
    }
};