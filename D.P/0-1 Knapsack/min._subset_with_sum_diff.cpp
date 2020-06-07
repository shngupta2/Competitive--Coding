// https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
#include <bits/stdc++.h>
using namespace std;

int subset(vector <int>& val, int sum) {
    int n = val.size();
    int t[n + 1][sum + 1];
    for(int i = 0; i < sum + 1; i++)
        t[0][i] = 0;
    for(int i = 0; i < n + 1; i++)
        t[i][0] = 1;
    for(int i = 1; i < n + 1; i++) 
        for(int j = 1; j < sum + 1; j++) 
            if(val[i - 1] <= j) 
                t[i][j] = max(t[i - 1][j - val[i - 1]], t [i - 1][j]);
            else 
                t[i][j] = t[i - 1][j];
                
    vector <int> k;
    for(int i = 0; i <= sum / 2; i++) {
        if(t[n][i] == 1) {
            k.push_back(i);
        }
    }
    int res = INT_MAX;
    for(int i = 0; i < k.size(); i++) {
        res = min(res, sum - (2 * k[i]));
    } 
    return res;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    cin>>n;
	    int sum = 0;
	    vector <int> val (n, 0);
	    for(int i = 0; i < n; i++) {
	        cin>>val[i];
            sum += val[i];
	    }
	    cout<<subset(val, sum)<<endl;
	    
	}
	return 0;
}
