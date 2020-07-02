// Question https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/submissions/

class Solution {
public:
    /*
            Approach
        it is generally an extended version of buy and sell stocks 3
        first check if k >= n / 2 means for each day one can buy or sell stocks then i became the problem of buy and sell stocks 2
        else make a array of buy and sell of size k as we know in previous proble we can sell stocks atmost 2 so we need 4 variable there but here it is k so take k size array of bothe buy and sell and compute as previous technique;
        
    */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(n <= 1 || k <= 0) 
            return 0;
        int profit = 0;
        if(k >= n / 2) {
            for(int i = 0; i < n - 1; i++) {
                if(prices[i] < prices[i + 1]) {
                    profit += prices[i + 1] - prices[i];
                }
            }
            return profit;
        }
        vector <int> buy(k, INT_MIN);
        vector <int> sell(k, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                buy[j] = max(buy[j], j == 0 ? 0 - prices[i] : sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};
