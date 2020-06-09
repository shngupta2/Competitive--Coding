//https://practice.geeksforgeeks.org/problems/count-palindromic-subsequences/1
int countPS(string str)
{
    int n = str.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) 
        dp[i][i] = 1;
    for(int l = 2; l <= n; l++) {
        for(int i = 0; i < n; i++) {
            int k = i + l - 1; // window of length l is created
            if(str[i] == str[k]) {
                dp[i][k] = dp[i + 1][k] + dp[i][k - 1] + 1;
            } else {
                dp[i][k] = dp[i + 1][k] + dp[i][k - 1] - dp[i +1][k - 1];
            }
        }
    }
    
    return dp[0][n - 1];
     //Your code here
}
