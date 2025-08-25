class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum_ = INT_MIN;
        max_sum(root, max_sum_);
        return max_sum_;
    }

    int max_sum(TreeNode* root, int& max_sum_) {
        if (root == nullptr) 
            return 0;

        // Recursive calls
        int left = max(0, max_sum(root->left, max_sum_));
        int right = max(0, max_sum(root->right, max_sum_));

        // Update global max: path through this node
        max_sum_ = max(max_sum_, root->val + left + right);

        // Return best downward path to parent
        return root->val + max(left, right);
    }
};
