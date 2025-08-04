class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {

        if (nums.size()==0) return {};

        vector<string> ranges;
        string range = to_string(nums[0]);
        int current_max = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                current_max = nums[i];
            } else {

                if (current_max <= stoi(range))
                    ranges.push_back(range);
                else
                    ranges.push_back(range + "->" + to_string(current_max));

                range = to_string(nums[i]);
            }
        }

        if (current_max <= stoi(range))
            ranges.push_back(range);
        else
            ranges.push_back(range + "->" + to_string(current_max));
        return ranges;
    }
};