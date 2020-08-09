// Question : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int profit = 0;
        int buy = -prices[0];
        int sell = 0;
        for(int i = 1; i < n; i++) {
            int nbuy = max(buy, sell - prices[i]);
            int nsell = max(sell, buy + prices[i] - fee);
            sell = nsell;
            buy = nbuy;
        }
        return sell;
    }
};
