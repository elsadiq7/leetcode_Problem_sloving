class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> output;
        // Min-heap to store {sum, index in nums1, index in nums2}
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        // Track visited pairs to avoid duplicates
        set<pair<int, int>> visited;

        // Push the first pair for each nums2 element with nums1[0]
        for (int j = 0; j < nums2.size() && j < k; ++j) {
            pq.push({nums1[0] + nums2[j], 0, j});
            visited.insert({0, j});
        }

        // Pop k smallest pairs
        while (k > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            output.push_back({nums1[i], nums2[j]});
            k--;

            // Push the next pair from nums1 (i+1, j) if valid and not visited
            if (i + 1 < nums1.size() && visited.find({i + 1, j}) == visited.end()) {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                visited.insert({i + 1, j});
            }
        }

        return output;
    }
};