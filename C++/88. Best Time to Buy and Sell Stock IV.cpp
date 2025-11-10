class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int profit = 0;
            for (int i = 1; i < n; i++)
                if (prices[i] > prices[i - 1])
                    profit += prices[i] - prices[i - 1];
            return profit;
        }

        vector<int> bestBuy(k + 1, INT_MAX);   
        vector<int> bestSell(k + 1, 0);        

        for (int price : prices) {
            for (int t = 1; t <= k; t++) {
                bestBuy[t] = min(bestBuy[t], price - bestSell[t - 1]);
                bestSell[t] = max(bestSell[t], price - bestBuy[t]);
            }
        }

        return bestSell[k];
    }
};
