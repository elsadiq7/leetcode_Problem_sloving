class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int hindex=0;
       
        for (int i=0;i<citations.size();i++)
        {
            if(citations[i]>i)
            {
                hindex++;
            }
        }
        return hindex;
    }
};

//link:https://leetcode.com/problems/h-index/?envType=study-plan-v2&envId=top-interview-150