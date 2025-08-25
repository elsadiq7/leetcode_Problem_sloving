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
    int sumNumbers(TreeNode* root) {
        int num = 0;

        return sum_tree(root, num);
    }

    int sum_tree(TreeNode* root, int curr) {
        if (!root)
            return 0;

        curr =curr*10+ root->val;

        if (!root->left && !root->right)
            return curr;

        return sum_tree(root->left, curr) + sum_tree(root->right, curr);
    }
};