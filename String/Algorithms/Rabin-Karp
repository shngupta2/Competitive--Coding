/* Naive String Search Algo
* string pat
* string text
* T.C = O(n*m)
*/

#include <bits/stdc++.h>
using namespace std;
void search(string txt, string pat) {
  int n = txt.size();
  int m = pat.size();
  int i, j;
  int q = 101; // prime no. for mod
  int d = 256; // total charchters in ascii table
  int p = 0;  // used to store value of pattern hash value
  int t = 0;  // used to store value of text hash value
  int h = 1;  // value i.e. pow(d, m  - 1)% q;
  
  for(i = 0; i < m - 1; i++)
    h = (h * d) % q;
    
  for(i = 0; i < m; i++) {
    p = (p * d + pat[i]) % q;
    t = (t * d + txt[i]) % q;
  }
  
  for(i = 0; i <= n - m; i++) {
    if(p == t) {
    for(j = 0; j < m; j++) {
      if(txt[i + j] != pat[j]) 
        break;
  }
    if(j == m) {
      cout<<"pattern found at index "<<i<<endl;
    }
    }
    if(i < n - m) {
      t = (d * (t - txt[i] * h) + txt[i + m]) % q;
      if(t < 0) {
      t += q;
      }
    }
 }
int main() 
{ 
    string txt = "AABAACAADAABAAABAA"; 
    string pat = "AABA"; 
    search(pat, txt); 
    return 0; 
} 
