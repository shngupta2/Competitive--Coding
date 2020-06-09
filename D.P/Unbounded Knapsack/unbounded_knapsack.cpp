#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n,m;
	    cin >> n >> m;
	    int wt[n], val[n];
	    for(int i = 0; i < n; i++) {
	        cin >> wt[i];
	    }
	    for(int i = 0; i < n; i++) {
	        cin >> val[i];
	    }
	    vector <vector <int> > dp(n + 1, vector <int> (m + 1));
	    for(int i = 0; i < n + 1; i++)
	        dp[i][0] = 0;
	    for(int i = 0; i < m + 1; i++) 
	        dp[0][i] = 0;
	    for(int i = 1; i < n + 1; i++) {
	        for(int j = 1; j < m + 1; j++) {
	            if(wt[i - 1] > j) {
	                dp[i][j] = dp[i - 1][j];
	            } else {
	                dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);

	            }
	        }
	    }
	    
	    cout<<dp[n][m]<<endl;
	}
	return 0;
}
