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
    vector<int> topView(Node *root) {
        // code here
        if(root == NULL) return {};
        queue<pair<Node*, int>> qu;
        map<int, int> mp;
        vector<int> ans;
        qu.push({root, 0});
        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            Node* node = it.first;
            int line = it.second;
             
            if(mp.find(line) == mp.end()){
                mp[line] = node -> data;
            }
            if(node -> left){
                qu.push({node -> left, line-1});
            }
            if(node -> right){
                qu.push({node -> right, line+1});
            }
        }
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};