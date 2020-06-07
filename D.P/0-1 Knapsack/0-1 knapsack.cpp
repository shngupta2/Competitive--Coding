// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem/0

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n;
	    int w;
	    cin>>n;
	    cin>>w;
	    vector <int> val (n, 0);
	    vector <int> wt (n, 0);
	    for(int i = 0; i < n; i++) 
	        cin>>val[i];
	  
	    for(int i = 0; i < n; i++) 
	        cin>>wt[i];
	        
	   vector <vector <int> > t(n + 1, vector <int> (w + 1, 0));
	   for(int i = 0; i < n + 1; i++) 
	    for(int j = 0; j < w + 1; j++) {
	        if(i == 0 || j == 0) {
	            t[i][j] = 0;
	        } else if(wt[i - 1] <= j) {
	            t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
	        } else  {
	            t[i][j] = t[i - 1][j];
	        }
	    }
	  
	    cout<<t[n][w]<<endl;
	}
	
	
	
	return 0;
}
