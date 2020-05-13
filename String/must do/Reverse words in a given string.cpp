#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    string s;
    while(t--) {
       stack <string> k;
       string p = "";
       cin>>s;
       int n = s.size();
       for(int i = 0; i < n; i++) {
           if(s[i] == '.') {
               k.push(p);
               p.clear();
           } else if(i == n - 1) {
               p += s[i];
               k.push(p);
               p.clear();
           } else {
               p += s[i];
           }
       }
       string res = "";
       while(!k.empty()) {
           p = k.top();
           k.pop();
           if(k.empty()) {
            res += p;
            p.clear();
           } else {
               res += p;
               res += '.';
               p.clear();
           }
       }
       cout<<res<<endl;
    }
    return 0;
}
