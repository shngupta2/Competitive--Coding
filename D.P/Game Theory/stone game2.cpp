// Question : https://leetcode.com/problems/stone-game-ii/submissions/

class Solution {
public:
    int get(vector <int>& piles, vector <int>& prefix, vector < vector <int> >& dp, int n, int i, int m) {
        if(i == n)
            return 0;
        if(dp[i][m] != -1)
            return dp[i][m];
        int ans = 0;
        for(int j = i; j < min(n, i + (2 * m)); j++) {
            ans = max(ans, prefix[n] - prefix[i] - get(piles, prefix, dp, n, j + 1, max(m, j - i + 1)));
        }
        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector <int> prefix(n + 1, 0);
        partial_sum(begin(piles), end(piles), begin(prefix) + 1);
        vector < vector <int> > dp(n, vector <int> (n, -1));
        return get(piles, prefix, dp, n, 0, 1);
    }
};
