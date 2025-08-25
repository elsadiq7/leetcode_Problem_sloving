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
    int countNodes(TreeNode* root) {
       int counter=0;
       count(root,counter);
       return counter;
        
    }

    void count(TreeNode* root, int & counter)
    {
        if(root==nullptr)  return ;

        counter++;
        count(root->left,counter);
        count(root->right,counter);
    }
};