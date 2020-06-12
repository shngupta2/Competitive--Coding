// https://leetcode.com/problems/stone-game/submissions/


class Solution {
public:
    int solve(int i, int j, vector<int>& piles, vector <vector <int> > & dp) {
        if(i == j - 1)
            return max(piles[i], piles[j]); // if there are two elements alex will selec the maximum one
        
        if(dp[i][j] != -1)
            return dp[i][j]; // if already find return
        int l = piles[i] + max(solve(i + 2, j, piles, dp), solve(i + 1, j - 1, piles, dp)); // if alex take ith pile
        int r = piles[j] + max(solve(i + 1, j - 1, piles, dp), solve(i, j - 2, piles, dp)); // if alex take jth pile
        
        return dp[i][j] = max(l, r);
    }
    

    bool stoneGame(vector<int>& piles) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        int l = 0;
        int n = piles.size();
        int r = piles.size() - 1;
        vector <vector <int> > dp(n, vector <int> (n, -1));    
        int alex = solve(l, r, piles, dp);
        
        return alex > sum - alex;
    }
};
