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
        bool isSymmetric(TreeNode* root) {
    
            vector<int> tree_left;
            vector<int> tree_right;
            preorder(root->left, tree_left, 1);
            preorder(root->right, tree_right, 0);
    
            if (tree_left.size() != tree_right.size())
    
                return false;
            for (int i = 0; i < tree_left.size(); i++) {
                if (tree_right[i] != tree_left[i])
                    return false;
            }
    
            return true;
        }
    
        void preorder(TreeNode* root, vector<int>& tree, bool leftFirst) {
            if (root == nullptr)
                {   
                    tree.push_back(-102);
                    return;
                }
            
            tree.push_back(root->val);
    
            if (leftFirst) {
                preorder(root->left, tree, 1);
                preorder(root->right, tree, 1);
            } else {
                preorder(root->right, tree, 0);
                preorder(root->left, tree, 0);
            }
        }
    };