class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int current_att=0;
        int max_att=0;
        for(int i=0;i<gain.size();i++)
        {
                current_att+=gain[i];
                max_att=max(max_att,current_att);
        }
        return max_att;
    }
};