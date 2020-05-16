// https://www.geeksforgeeks.org/print-all-permutations-of-a-string-with-duplicates-allowed-in-input-string/
/*  
 * T.C = O(n ^ 2 * n !)
 * S.C = o(1)
 * revisie https://www.youtube.com/watch?v=nYFd7VHKyWQ&t=324s
 * if you want to print all uniwue permutation of the string with duplicates if space is not a problem you can use 
 * set with normal permutation algo but if you want to do this in O(1) space use this approach.
 */

#include <bits/stdc++.h>
using namespace std;

// function to print the string 

void print(vector <char> results) {
  for(int i = 0; i < results.size(); i++) {
    cout<<results[i];
     }
     cout<<endl;
 }

// function for finding all unique permutation
void permute(vector <char> chars, vector <int> count, vector<char> res, int level) {
  if(level == res.size()) {
    print(res);
    return;
    }
    for(int i = 0; i < res.size(); i++) {
        if(counts[i] != 0) {
          res[level] = chars[i];
          count[i]--;
          permute(chars, count, res, level + 1);
          count[i]++;
      }
    }
 }
 
// function to make count array of the string
void sortedpm(string x) {
  map <char, int> m;
  vector <char> chars;
  vector <int> count;
  map <char, int> :: iterator it;
  for(int i = 0; i < x.size(); i++) { 
      m[x[i]]++;
    }
  for(it = m.begin(); it != m.end(); it++) {
    chars.push_back(it->first);
    chars.push_back(it->second);
  }
  int n = x.size();
  vector <char> res (n);
  permute(chars, count, res, 0);
}

int main() {
  string x;
  cin>>x;
  sortedpm(x);
  
  return 0;
  }
