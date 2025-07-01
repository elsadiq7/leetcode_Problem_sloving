#include <cmath>
#include <bits/stdc++.h>
class Solution {
public:
    struct cc {
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return sqrt(a[0] * a[0] + a[1] * a[1]) >
                   sqrt(b[0] * b[0] + b[1] * b[1]);
        }
    };
     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>, cc> pd;

        for (int i = 0; i < points.size(); i++) {
            pd.push(points[i]);
        }
    

        vector<vector<int>> points_me;
        for (int i = 0; i < k; i++) {
            points_me.push_back(pd.top());
            pd.pop();
        }
        return points_me;
    }
};