//Question https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void printperm(string s, int l, int r) {
    if(l == r) {
        cout<<s<<" ";
    } else {
        for(int i = l; i <= r; i++) {
        swap(s[l], s[i]);
        // sort for lexicographic order
        sort(s.begin() + l + 1, s.end());
        printperm(s, l + 1, r);
        // sort for lexicographic order
        sort(s.begin() + l + 1, s.end());
        swap(s[l], s[i]);
        }
    }
}

int main() {
	//code
	int t;
	cin>>t;
	string s;
	while(t--) {
	    cin>>s;
	    int n = s.size();
      // sort for lexicographic order
	    sort(s.begin(), s.end());
	    printperm(s, 0, n - 1);
	    cout<<endl;
	    
	}
	
	return 0;
}
