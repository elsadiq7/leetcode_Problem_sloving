#include <numeric>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

class Solution {
public:
    set<vector<int>> uniqueResult;
    vector<int> path;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates, target);
        // convert set to vector
        return vector<vector<int>>(uniqueResult.begin(), uniqueResult.end());
    }

    void backtrack(vector<int>& nums, int target) {
        int sum = accumulate(path.begin(), path.end(), 0);
        if (sum == target) {
            vector<int> temp = path;
            sort(temp.begin(), temp.end()); // ensure sorted before inserting
            uniqueResult.insert(temp);
            return;
        }
        if (sum > target) return;

        for (int i = 0; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, target);
            path.pop_back();
        }
    }
};
