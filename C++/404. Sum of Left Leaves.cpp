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
        int sumOfLeftLeaves(TreeNode* root) { return sum_left_leafes(root); }
    
        int sum_left_leafes(TreeNode* root) {
    
            if (root == nullptr)
                return 0;
    
            else if ((root->left != nullptr&&
                      root->left->left == nullptr &&
                      root->left->right == nullptr)) {
                return root->left->val + sum_left_leafes(root->right);
            }
    
            int right = sum_left_leafes(root->right);
            int left = sum_left_leafes(root->left);
            return right + left;
        }
    };