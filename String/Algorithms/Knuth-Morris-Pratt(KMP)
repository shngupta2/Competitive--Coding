/* KMP string search algo
* T.C = O(n);
* based on prefix and suffix concept
* revise using karamunchi and abdul bari video
*/


#include<bits/stdc++.h>
using namespace std;
KMPSearch(string pat, string txt) {
  int n = txt.size();
  int m = pat.size();
  vector <int> lps(m, 0);
  computelps(pat, lps);
  int i = 0;
  int j = 0;
  while(i < n) {
    if(txt[i] == pat[j]) {
      if(j == m - 1) {
        cout<<"pattern found at "<<i - j<<endl;
      } else {
        i++;
        j++;
       }
  }
  else if(j > 0) {
    j = lps[j - 1];
  }
  else {
  i++;
}
}
}
  
  void computelps(string pat, vector <int>& lps) 
  {
    int m = lps.size();
    int j = 0;
    int i = 1;
    while(i < m) {
      if(pat[i] == pat[j]) {
        lps[i] = j + 1;
        i++;
        j++;
    }
    else {
      if(j > 0) {
      j = lps[j - 1];
      }
      else {
      lps[i] = 0;
      i++;
      }
    }
  }
}


int main() {
  string txt = "ABABDABACDABABCABAB";
  string pat = "ABABCABAB";
  KMPSearch(pat, txt); 
    return 0; 
    }
  
