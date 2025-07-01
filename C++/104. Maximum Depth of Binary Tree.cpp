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
        int maxDepth(TreeNode* root) {
              return check_depth(root);
        }
    
    
        int check_depth (TreeNode* root)
        {
            if (root== nullptr)
            {
                return 0;
            }
    
            int left =check_depth(root->left);
            int  right =check_depth(root->right);
    
            return 1+max(left,right);
    
        }
    };