/*
 *here you can see two structure of trie
 *1 it is based on only alphabets i.e. if we want to develop trie only for alphabets
 *2 it can work with any character exist so we will use map for this
 */
 
 #include <bits/stdc++.h>
  using name space std; 
  
//1
  struct TrieNode {
  vector<TrieNode*> child(26);
  bool eof; // isEndOfWord;
  };
  
//2
   struct TrieNode {
    map<char, TrieNode*> child;
    bool eof; //isEndOfWord;
    };
    
// function for initaializing the Trie Node
struct TrieNode * getNode() {
  struct TrieNode * p = new TrieNode;
  eof = false;
  for(int i = 0; i < 26; i++) 
      p->child[i] = NULL;
      
  return p;
  }
  
  int main() {
    struct TrieNode * root = getNode();
    
    return 0;
    }
  
