// Question : https://leetcode.com/problems/divisor-game/submissions/

class Solution {
public:
    /*      Approach
    *   Alice wins iff after his moves the move which left results to fail
    *   n == 0 Alice has no chance Alice fails
    *   n == 1 Alice has no chance alice fails
    *   n == 2 if alice choose 1 as 0 < 1 < 2(N) the remaining is 1 which has results alse so Alice wins
    *   n >= 3 if i between 0 to n results true and n - i rersults false onl;y then alice can win
    */
    bool divisorGame(int N) {
        vector <bool> dp(N + 1, false);
        if(N >= 2)
        dp[2] = true;
        for(int i = 2; i <= N; i++) {
            dp[i] = false;
            for(int j = 1; j < i; j++) {
                if(i % j == 0 && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[N];
    }
};
