// Question https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
         int profit = 0;
         int min = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(min > prices[i]) {
                min = prices[i];
            } else if(profit < prices[i] - min) {
                profit = prices[i] - min;
            }
        }
            return profit;
    }
};
