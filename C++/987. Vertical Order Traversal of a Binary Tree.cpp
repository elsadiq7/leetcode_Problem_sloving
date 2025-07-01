/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            map<int, map<int, vector<int>>> nodes; // Map to store (col -> (row -> values))
            vector<vector<int>> vec_levels;
    
            dfs(root, 0, 0, nodes); // Correct variable name
    
            for (auto& [col, row_map] : nodes) {
                vector<int> col_values;
                for (auto& [row, values] : row_map) {
                    sort(values.begin(), values.end()); // Sort values for tie-breaking
                    col_values.insert(col_values.end(), values.begin(), values.end());
                }
                vec_levels.push_back(col_values);
            }
            return vec_levels;
        }
    
    private:
        void dfs(TreeNode* root, int row, int col, map<int, map<int, vector<int>>>& nodes) {
            if (!root) return;
    
            nodes[col][row].push_back(root->val);
            dfs(root->left, row + 1, col - 1, nodes);
            dfs(root->right, row + 1, col + 1, nodes);
        }
    };
    