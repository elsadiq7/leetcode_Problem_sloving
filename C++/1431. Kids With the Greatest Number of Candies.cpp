class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxone=*max_element(candies.begin(),candies.end());
        vector<bool>have_max(candies.size(),false);

        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]+extraCandies>=maxone)
                 have_max[i]=true;
        }

        return have_max;
        
    }
};