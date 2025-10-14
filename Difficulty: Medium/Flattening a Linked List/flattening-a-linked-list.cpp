/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* convert(vector<int> arr){
        int n = arr.size();
        if(n == 0) return NULL;
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1; i<n; i++){
            Node* node = new Node(arr[i]);
            temp -> bottom = node;
            temp = temp -> bottom;
        }
        return head;
    }
    Node *flatten(Node *root) {
        // code here
        vector<int> list;
        Node* temp = root;
        while(temp != NULL){
            Node* t = temp;
            while(t != NULL){
                list.push_back(t -> data);
                t = t -> bottom;
            }
            temp = temp -> next;
        }
        sort(list.begin(), list.end());
        Node* head = convert(list);
        return head;
    }
};