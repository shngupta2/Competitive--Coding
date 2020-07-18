// Question https://leetcode.com/problems/palindrome-partitioning-ii/

class Solution {
public:
  
    int minCut(string s) {
        int n = s.size();
        // dp [i][j] tells whether substring from i to j is palindrome or not
        vector < vector < bool> > dp(n , vector < bool> (n , false));
        // cut[i] tells minimum no. of cut required upto position i such that each partition bercomes palindrome
        vector <int> cut(n);
        // loop from i = 1 to length of string because as we know eacjh character is palindrome so for 0th it will be 0 cuts required
        for(int i = 1; i < n; i++) {
            int mine = i;   // in the worst case it will require i cuts to make each partition palindrome i because it is 0 based indexing
            
            // for each position iterate a loop from 0th position to ith position to find minimum cuts
            for(int j = 0; j <= i; j++) {
                
                /*
                    If character at ith and jth position matches then there will be two conditions so that substr from i to j become palindrome i.e. s[i] == s[j]
                    1- j and i both at same position i.e. i <= j + 1
                                or
                    2- substr j + 1 and i - 1 is also a palindrome i.e. dp[i - 1][j + 1] == true
                    
                    then mark substr i to j as true dp[i][j] = true
                    and min length = min(previously calculated length, ifj is at position 0 means whole substr requires 0 cuts if j is not 0 and substr from j to i is palindrome then minimum cut will be cut from(0 to j - 1) + 1 cut + 0(because substr from j to i is palindrome);
                
                */
                if(s[i] == s[j] && (i <= j + 1 || dp[i - 1][j + 1])) {
                    dp[i][j] = true;
                    mine = min(mine, j == 0 ? 0 : 1 + cut[j - 1]);
                }
            }
            // store the minimum cuts till i in cut [i]
            cut[i] = mine;
            
        }
        // cut[string length - 1] stores the result minimm cut from 0 to string length - 1;
        return cut[n - 1];
    }
};
