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
    int maxDiameter=0;
    int diameterOfBinaryTree(TreeNode* root) {
          check_dpeth(root);
          return maxDiameter;
    }

    int check_dpeth(TreeNode* root)
    {
        if (root==nullptr)
          return 0 ;

        int left=check_dpeth(root->left);
        int right=check_dpeth(root->right);
        
        maxDiameter = max(maxDiameter, left + right);

        return 1+ max(left,right);
    }
};