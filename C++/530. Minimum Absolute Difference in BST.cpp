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
 #include <cmath>
class Solution {
public:
    int first = 0;
    int second = 0;
    int getMinimumDifference(TreeNode* root) {
        vector<int>tree;
        postorder( root, tree);
        sort(tree.begin(),tree.end()); 
        int min=100000;

        for (int i=0;i<tree.size()-1;i++)
        {   int diff=tree[i+1]-tree[i];
            if (diff<min)
            {
                min=diff;
            }
        }

        return min;
        
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
