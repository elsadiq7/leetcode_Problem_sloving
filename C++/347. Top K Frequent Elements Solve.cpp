#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> hashtable;
            vector<int> result(k);
            for (int i = 0; i < nums.size(); i++) {
                if (hashtable.count(nums[i]))
                    hashtable[nums[i]] += 1;
                else
                    hashtable[nums[i]] = 1;
            }
            vector<pair<int, int>> vec(hashtable.begin(), hashtable.end());
            sort(vec.begin(), vec.end(),
                 [](const pair<int, int>& a, const pair<int, int>& b) {
                     return a.second > b.second;
                 });
    
            for (int i = 0; i < k; i++) {
                result[i] = vec[i].first;
            }
            return result;
        }
    };