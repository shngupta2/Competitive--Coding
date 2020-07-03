// Question https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/

class Solution {
public:
    /*
                Approach
    case 1: when we have a stock on day i : dp[i][1]
        1.1: we have bought on same day
                dp[i - 2][0] - prices[i];
        1.2: we have carry forwarding
                dp[i - 1][1];
    case 2: when we do not have stock on day i: dp[i][0]
        2.1: we have selled it today
                dp[i - 1][1] + prices[i];
        2.2: we have carry forwarding
                dp[i - 1][0];
    
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) // no transaction can be done
            return 0;
        /*
        if there are two days then it means one txn can be done if prices[1] > prices[0]
        else profit will be zero
        */
        if(n == 2 && prices[1] > prices[0])
            return prices[1] - prices[0];
        else if(n == 2 && prices[1] < prices[0])
            return 0;
        vector <vector <int> > dp(n, vector <int> (2, 0));
        dp[0][0] = 0; // we have no stock on that day
        dp[0][1] = -prices[0]; // we have stock on that day means we have bought it on same day
        dp[1][0] = max(dp[0][1] + prices[1], dp[0][0]);
        dp[1][1] = max(dp[0][0] - prices[1], dp[0][1]);
        
        for(int i = 2; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
            
        }   
        return dp[n - 1][0];
    }
};
