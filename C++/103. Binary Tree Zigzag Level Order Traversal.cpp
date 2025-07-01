/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> my_levels;
            if (!root) return my_levels;  // Edge case: empty tree
    
            queue<TreeNode*> q;
            q.push(root);
            bool left_right = true;
    
            while (!q.empty()) {
                int level_size = q.size();  // Number of nodes at the current level
                vector<int> sub_array(level_size);  // Store level nodes
    
                for (int i = 0; i < level_size; i++) {
                    TreeNode* front = q.front();
                    q.pop();
    
                    // Insert at the correct position based on left_right
                    int index = left_right ? i : (level_size - 1 - i);
                    sub_array[index] = front->val;
    
                    // Enqueue children for next level
                    if (front->left) q.push(front->left);
                    if (front->right) q.push(front->right);
                }
    
                my_levels.push_back(sub_array);
                left_right = !left_right; 
            }
    
            return my_levels;
        }
    };