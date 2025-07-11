/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int res = -1;
        while(root != NULL){
            if(k >= root->data){
                res = root->data;
                root = root -> right;
            }
            else{
                root = root -> left;
            }
        }
        return res;
    }
};