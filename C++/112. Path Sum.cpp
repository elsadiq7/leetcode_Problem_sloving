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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;

        else
          {
             if (check_sum(root, 0,targetSum)>0)
               return true; 
            else 
              return false;

          } 
    }

    int check_sum(TreeNode* root, int sum,int& targetSum ) {
        if (root == nullptr)
            return 0;
        sum += root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return sum==targetSum;

            
        }

        return check_sum(root->left, sum,targetSum )+check_sum(root->right, sum,targetSum );

    }
};