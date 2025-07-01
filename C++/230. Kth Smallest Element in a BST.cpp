class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            vector<int>tree;
            postorder( root, tree);
            sort(tree.begin(),tree.end()); 
            return tree[k-1];
    
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