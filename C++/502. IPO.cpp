class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());

        priority_queue<int> maxProfitHeap;
        int ptr = 0;
        for (int i = 0; i < k; i++) {

                while (ptr < projects.size() && projects[ptr].first <= w) {
                maxProfitHeap.push(projects[ptr].second); // Push profit
                ptr++;
            }

            if (maxProfitHeap.empty()) {
                break;
            }

            w += maxProfitHeap.top();
            maxProfitHeap.pop();
        }

        return w;
    }
};