/*
 *here you can see search on trie it will be word based search and we have both recursive and iterative implementation
 * T.C = O(m)
 * m = maximum length of string;
 */
 
 #include <bits/stdc++.h>
  using namespace std; 
  
  // Structure of Trie Node;
  struct TrieNode {
  struct TrieNode *child[26];
  bool eof; // isEndOfWord;
  };
  
  // Initialization of new Trie Node
struct TrieNode * getNode() {
  struct TrieNode * p = new TrieNode;
  p->eof = false;
  for(int i = 0; i < 26; i++) 
      p->child[i] = NULL;
      
  return p;
  }
  
  // iterative version of insertion start
  void insert(struct TrieNode *root, string key) {
    struct TrieNode *p = root;
    for(int i = 0; i < key.size(); i++) {
        int  ind = key[i] - 'a';
        if(!p->child[ind]) 
            p->child[ind] = getNode();
        p = p->child[ind];
        }
        p->eof = true;
    }
 // iterative version of insertion end
 
 // recursive insertion start
  void insertRecursive(struct TrieNode* curr, string key, int index) {
      if(index == key.size()) {
        curr->eof = true;
        return;
      }
      int  ind = key[index] - 'a';
        if(!curr->child[ind]) 
            curr->child[ind] = getNode();
        curr = curr->child[ind];
        
        insertRecursive(curr, key, index + 1);
}
 // start function for recursive insertion 
  void insertrecur(struct TrieNode* root, string key) {
      insertRecursive(root, key, 0);
  }
// recurive insertion end

// word based iterative search start
  
  bool search(struct TrieNode *root, string key) {
      struct TrieNode* p = root;
      for(int i = 0; i < key.size(); i++) {
        int ind = key[i] - 'a';
        if(!p->child[ind])
          return false;
        p = p->child[ind];
        }
        
        return (p != NULL && p->eof);
  }
// word based iterative search end

// word based recursive search start 
   
  bool searchRecursive(struct TrieNode *curr, string key, int index) {
    if(index == key.size())
        return curr->eof;
   int  ind = key[index] - 'a';
        if(!curr->child[ind]) 
            return false;
        curr = curr->child[ind];
        
       return searchRecursive(curr, key, index + 1);
  }
  
  
  bool searchrec(struct TrieNode *root, string key) {
      return searchRecursive(root, key, 0);
   }
  // word based recursive search end
  
  int main() {
    struct TrieNode * root = getNode();
    string keys[] = {"the", "a", "hi", "hello", "there", "answer", "no", "bye", "their"};
    int n = sizeof(keys)/ sizeof(keys[0]);
    for(int i = 0; i < n; i++) 
      insertrecur(root, keys[i]);
     
     searchrec(root, "the")? cout<<"Yes\n" : cout<<"No"<<endl;
     searchrec(root, "there")? cout<<"Yes\n" : cout<<"No"<<endl;
     searchrec(root, "their")? cout<<"Yes\n" : cout<<"No"<<endl;
     searchrec(root, "then")? cout<<"Yes\n" : cout<<"No"<<endl;
     searchrec(root, "them")? cout<<"Yes\n" : cout<<"No"<<endl;
    return 0;
    }
  
