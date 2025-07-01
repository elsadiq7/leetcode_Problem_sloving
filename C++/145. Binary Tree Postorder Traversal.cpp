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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> tree;
            postorder(root, tree);
            return tree;
        }
    
        void postorder(TreeNode* root, vector<int>& tree) {
            if (root == nullptr) {
                return;
            }
    
            postorder(root->left, tree);
            postorder(root->right, tree);
            tree.push_back(root->val);
        }
    };