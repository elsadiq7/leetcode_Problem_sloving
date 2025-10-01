class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<bool> used;

    vector<vector<int>> permute(vector<int>& nums) {
        used = vector<bool>(nums.size(), false);
        backtrack(nums);
        return result;
    }

    void backtrack(vector<int>& nums) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;  

            path.push_back(nums[i]);
            used[i] = true;

            backtrack(nums);

            path.pop_back();
            used[i] = false;
        }
    }
};
