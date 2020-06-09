//https://practice.geeksforgeeks.org/problems/number-of-coins/0
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int v;
	    int n;
	    cin>>v;
	    cin>>n;
	    vector <int> coin (n, 0);
	    for(int i = 0; i < n; i++)
	        cin>>coin[i];
	    vector <vector <int> > dp(n + 1, vector <int> (v + 1, 0));
	    for(int i = 0; i < n + 1; i++) {
	        for(int j = 0; j < v + 1; j++) {
	            if(i == 0)
	                dp[i][j] = INT_MAX - 1;
	            else if(j == 0 && i != 0) 
	                dp[i][j] = 0;
	            else if(i == 1 && j != 0) {
	                if(j % coin[0] == 0) {
	                    dp[i][j] = j / coin[0];
	                } else {
	                    dp[i][j] = INT_MAX - 1;
	                }
	            } else if(coin[i - 1] <= j) {
	                dp[i][j] = min(1 + dp[i][j - coin[i - 1]], dp[i - 1][j]);
	            } else {
	                dp[i][j] = dp[i - 1][j];
	            }
	        }
	    }
	    if(dp[n][v] == INT_MAX - 1)
	        cout<<-1<<endl;
	    else
	        cout<<dp[n][v]<<endl;
	}
	return 0;
}
