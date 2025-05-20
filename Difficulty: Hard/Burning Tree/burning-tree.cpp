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
    int minTime(Node* root, int target) {
        // code here
       if (!root) return 0;
    
    // Map to store parent pointers
    unordered_map<Node*, Node*> parentMap;
    parentMap[root] = nullptr;
    
    // Queue for BFS to build parent map and find target node
    queue<Node*> q;
    q.push(root);
    
    Node* targetNode = nullptr;
    
    // Build parent map and locate target node
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr->data == target)
            targetNode = curr;
        
        if (curr->left) {
            parentMap[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parentMap[curr->right] = curr;
            q.push(curr->right);
        }
    }
    
    // BFS to simulate burning
    unordered_map<Node*, bool> visited;
    q.push(targetNode);
    visited[targetNode] = true;
    
    int time = 0;
    
    while (!q.empty()) {
        int size = q.size();
        bool burntNewNode = false;
        
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            
            // Check left child
            if (curr->left && !visited[curr->left]) {
                visited[curr->left] = true;
                q.push(curr->left);
                burntNewNode = true;
            }
            // Check right child
            if (curr->right && !visited[curr->right]) {
                visited[curr->right] = true;
                q.push(curr->right);
                burntNewNode = true;
            }
            // Check parent
            Node* par = parentMap[curr];
            if (par && !visited[par]) {
                visited[par] = true;
                q.push(par);
                burntNewNode = true;
            }
        }
        
        if (burntNewNode) time++;  // Increase time only if new nodes got burnt
    }
    
    return time; 
    }
};