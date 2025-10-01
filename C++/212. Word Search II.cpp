class Solution {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        string word;  // stores word when reaching the end
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                if (!node->children.count(c)) {
                    node->children[c] = new TrieNode();
                }
                node = node->children[c];
            }
            node->word = w; // mark the end of the word
        }
        return root;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size(), cols = board[0].size();
        TrieNode* root = buildTrie(words);
        vector<string> result;

        function<void(int,int,TrieNode*)> dfs = [&](int r, int c, TrieNode* node) {
            char ch = board[r][c];
            if (!node->children.count(ch)) return;
            node = node->children[ch];

            if (!node->word.empty()) {  // found a word
                result.push_back(node->word);
                node->word.clear(); // avoid duplicates
            }

            board[r][c] = '#'; // mark visited
            vector<pair<int,int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '#') {
                    dfs(nr, nc, node);
                }
            }
            board[r][c] = ch; // backtrack
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                dfs(r, c, root);
            }
        }

        return result;
    }
};
