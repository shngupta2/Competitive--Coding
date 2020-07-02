// Question https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/submissions/

class Solution {
public:
    /*
                                            Approach
        we have to maintain 4 variables first buy(fb), first sell(fs), second buy(sb), second sell(ss);
        second sell will be the profit we have earned while selling the stocks;
        first buy amount paid to buy that stock
        first sell amount earned by selling first stock
        second buy amount paid from first sell to buy 2nd stock
        second sell amount earbned by selling 2nd stock
        fs and ss are the profits earned by selling the stocks so initialize them with 0 means no profit earned;
        fb and sb initialize them with INT_MIN;
        after that will traversing we have to maintain min value in fb and sb so thst we are taking negation
        which will ensure min value in that;
        return simply ss thats the final profit
    */
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)
            return 0;
        int fb = INT_MAX, sb = INT_MIN;
        int fs = 0, ss = 0;
        for(int i = 0; i < n; i++) {
            fb = min(fb, prices[i]); // min valuee of fb
            fs = max(fs, prices[i] - fb); //max value obtained by selling first stock
            sb = max(sb, fs - prices[i]); // max difference i.e. fs - prices[i] it will ensue min value of 2nd stock;
            ss = max(ss, sb + prices[i]);
        }
        return ss;
    }
};
