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
private:
    int postorderIndex;
    unordered_map<int, int> mapping;

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mapping.clear();
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }

        postorderIndex = postorder.size()-1;
        return build(postorder, 0, inorder.size() - 1);
    }

private:
    TreeNode* build(vector<int>& postorder, int start, int end) {
        if (start > end)
            return nullptr;

        int rootVal = postorder[postorderIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int mid = mapping[rootVal];
        root->right = build(postorder, mid + 1, end);
        root->left = build(postorder, start, mid - 1);

        return root;
    }
};






