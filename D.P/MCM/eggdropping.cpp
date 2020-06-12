// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle/0
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solve(int e, int f, vector <vector <int> >& t) {
    if(f == 1 || f == 0) // if n. of floors are 1 or 0 it will take max f attempts
        return f;
    
    if(e == 1) // if no. of eggs are 1 we start from bottom and it will take max f attempts to find threshold floor
        return f;
    
    if(t[e][f] != -1)
        return t[e][f];
        
    int minv = INT_MAX;
    for(int k = 1; k <= f; k++) {
        int low, high;
        if(t[e - 1][k - 1] != -1)
            low = t[e - 1][k - 1];
        else {
            low = solve(e - 1, k - 1, t);
            t[e - 1][k - 1] = low;
        }
        if(t[e][f - k] != -1)
            high = t[e][f - k];
        else {
            high = solve(e, f - k, t);
            t[e][f - k] = high;
        }
        int tmp = 1 + max(low, high);
        minv = min(minv, tmp);
     }
      return t[e][f] = minv;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
	    int n, f;
	    cin>>n>>f;
	    vector <vector <int> > t(n + 1, vector <int> (f + 1, -1));
	    cout<<solve(n, f, t)<<endl;
	}
	return 0;
}
