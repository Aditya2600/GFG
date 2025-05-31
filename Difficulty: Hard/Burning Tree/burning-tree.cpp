/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    
    int findMaxDistance(map<Node*, Node*> &mpp, Node* target){
        queue<Node*> q;
        map<Node* , bool> vis;
        q.push(target);
        vis[target] = true;
        int maxi = 0;
        while(!q.empty()){
            int sz = q.size();
            int fl = false;
            for(int i = 0; i < sz; i++){
                auto node = q.front();
                q.pop();
                if(node -> left && !vis[node -> left]){
                    fl = true;
                    vis[node -> left] = true;
                    q.push(node -> left);
                }
                if(node -> right && !vis[node -> right]){
                    fl = true;
                    vis[node -> right] = true;
                    q.push(node -> right);
                }
                if(mpp.find(node) != mpp.end() && !vis[mpp[node]]){
                    fl = true;
                    vis[mpp[node]] = true;
                    q.push(mpp[node]);
                }
            }
            if(fl) maxi++;
        }
        return maxi;
    }
    Node* bfsToMapParent(Node* root, map<Node*, Node*> &mpp, int target){
        queue<Node*> q;
        q.push(root);
        Node* res = nullptr;
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr -> data == target){
                res = curr;
            } 
            if(curr -> left){
                mpp[curr -> left] = curr;
                q.push(curr -> left);
            }
            if(curr -> right){
                mpp[curr -> right] = curr;
                q.push(curr -> right);
            }
        }
        return res;
    }
    int minTime(Node* root, int target) {
        // code here
         map<Node*, Node*> mpp;
         Node* start = bfsToMapParent(root, mpp, target);
         int maxi = findMaxDistance(mpp, start);
         return maxi;
    }
};