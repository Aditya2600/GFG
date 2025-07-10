class TrieNode {
public:
    TrieNode* children[26] = {};
    bool isWord = false;
    string word = "";
};

class Solution {
public:
    string longestString(vector<string>& words) {
        TrieNode* root = new TrieNode();

        // Step 1: Build Trie
        for (string& word : words) {
            TrieNode* node = root;
            for (char c : word) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->isWord = true;
            node->word = word;
        }

        // Step 2: BFS traversal for lexicographically smallest longest word
        string result = "";
        queue<TrieNode*> q;
        q.push(root);

        while (!q.empty()) {
            TrieNode* curr = q.front();
            q.pop();

            for (int i = 25; i >= 0; --i) { // Reverse for lexicographically smaller word in BFS
                TrieNode* child = curr->children[i];
                if (child && child->isWord) {
                    q.push(child);
                    if (child->word.length() > result.length() ||
                       (child->word.length() == result.length() && child->word < result)) {
                        result = child->word;
                    }
                }
            }
        }

        return result;
    }
};