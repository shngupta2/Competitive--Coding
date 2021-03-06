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
  for(int i = 0; i < n - m; i++) {
      int j;
      for(int j = 0; j < m; j++) 
        if(txt[i + j] != pat[j]) 
          break;
        
       if(j == m) {
        cout<<"pattern found at "<<i<<endl;
       } 
    }
    cout<<"not found"<<endl;
}
int main() 
{ 
    string txt = "AABAACAADAABAAABAA"; 
    string pat = "AABA"; 
    search(pat, txt); 
    return 0; 
} 
