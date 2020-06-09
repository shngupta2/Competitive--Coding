//https://practice.geeksforgeeks.org/problems/coin-change/0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int m;
	    cin>>m;
	    vector <int> coin(m, 0);
	    for(int i = 0; i < m; i++) 
	        cin>>coin[i];
	    int n;
	    cin>>n;
	    vector < vector <int> > t(m + 1, vector <int> (n + 1, 0));
	    for(int i = 0; i < m + 1; i++) {
	        for(int j = 0; j < n + 1; j++) {
	            if(i == 0)
	                t[i][j] = 0;
	            else if(j == 0) 
	                t[i][j] = 1;
	            else if(coin[i - 1] <= j)
                    t[i][j] = t[i][j - coin[i - 1]] + t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
	        }
	    }
	    cout<<t[m][n]<<endl;
	}
	return 0;
}
