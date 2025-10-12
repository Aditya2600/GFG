/*The Node structure is defined as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// return the Kth largest element in the given BST rooted at 'root'
class Solution {
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        Node* curr = root;
        vector<int> ans;
        int cnt = 0;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->data);
                curr = curr->right;
            } else {
                Node* prev = curr;
                prev = prev->left;               
                while (prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev -> right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev -> right = NULL;
                    ans.push_back(curr->data);
                    curr = curr->right;
                }
            }
        }
        int m = ans.size();
        return ans[m-k];
    }
};