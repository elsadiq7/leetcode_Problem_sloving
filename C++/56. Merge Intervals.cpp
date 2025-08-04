class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ranges;
        vector<int> range = intervals[0];
        
        for (int i = 1; i < intervals.size(); i++) {
            if (range[1] >= intervals[i][0]) {
                range[1] = max(range[1], intervals[i][1]);
            } else {
                ranges.push_back(range);
                range = intervals[i];
            }
        }
        
        ranges.push_back(range);
        
        return ranges;
    }
};
