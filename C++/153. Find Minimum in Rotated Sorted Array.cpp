class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int minn = INT_MAX;
        int mid;
        while (low <= high) {
            mid = low + (high - low) / 2;

            minn = min(minn, nums[mid]);
            if (nums[high] > nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return minn;
    }
};