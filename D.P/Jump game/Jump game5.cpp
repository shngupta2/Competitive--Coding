// Question : https://leetcode.com/problems/jump-game-v/submissions/

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        vector < pair <int, int> > v;
        int n = arr.size();
        
        for(int i = 0; i < arr.size(); i++) {
            v.push_back({arr[i], i});    
        }
        if(n == 1)
            return 1;
        sort(v.begin(), v.end());
        vector <int> dp(n, 0);
        dp[v[0].second] = 1;
        int res = INT_MIN; 
        for(int i = 1; i < n; i++) {
            int h = v[i].first;
            int ind = v[i].second;
            int val = 1;
            if(ind + 1 < n)
            for(int j = ind + 1; j <=  min(n - 1, (ind + d)); j++) {
                if(arr[j] < h) {
                    val = max(val, dp[j] + 1);
                } else {
                    break;
                }
            }
            if(ind - 1 >= 0)
            for(int j = ind - 1; j >=  max(0 , ind - d); j--) {
                if(arr[j] < h) {
                    val = max(val, dp[j] + 1);
                } else {
                    break;
                }
            }
            dp[ind] = val;
            res = max(res, dp[ind]);
        }
        return res;
     
    }
};
