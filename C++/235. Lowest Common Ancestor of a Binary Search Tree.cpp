/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            int p_val = p->val;
            int q_val = q->val;
    
            return find_p(root, p_val, q_val);
        }
    
        TreeNode* find_p(TreeNode* root, int& p, int& q) {
            if (root == nullptr || root->val == p || root->val == q)
                return root;
    
            TreeNode* left = find_p(root->left, p, q);
            TreeNode* right = find_p(root->right, p, q);
            if (left != nullptr && right != nullptr)
                return root;
            return left != nullptr ? left : right;
        }
    };