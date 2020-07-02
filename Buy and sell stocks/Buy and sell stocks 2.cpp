// Question https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 0)
            return 0;
        int profit = 0;
        for(int i = 0; i < n - 1; i++) {
            if(prices[i] < prices[i + 1]) 
                profit += prices[i + 1] - prices[i];
        }
        return profit;
    }
};
