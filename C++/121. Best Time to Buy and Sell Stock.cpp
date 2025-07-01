#include <algorithm>
#include <vector>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price ,profit=0;
        min_price=prices[0];
        int counter=0;
        for (int i:prices)
        { 
            
            min_price = min(min_price, i); // Update min price

            profit=max(profit,i-min_price);
        }

        return profit;
    }
};