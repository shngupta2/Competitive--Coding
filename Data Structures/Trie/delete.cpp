/*
 *here you can see delete operation on trie.
 * T.C = O(l)
 * l = maximum length of string;
 */
 
 #include <bits/stdc++.h>
  using namespace std; 
  
  struct TrieNode {
  struct TrieNode *child[26];
  bool eof; // isEndOfWord;
  };
  
  
struct TrieNode * getNode() {
  struct TrieNode * p = new TrieNode;
  p->eof = false;
  for(int i = 0; i < 26; i++) 
      p->child[i] = NULL;
      
  return p;
  }
  
  // iterative insertion
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
 
 
 // recursive insertion
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
  
  // word based iterative search
  
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
  
  // word based recursive search
   
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
  
  bool isEmpty(TrieNode* root) {
    for(int i = 0; i < 26; i++) {
      if(root->child[i])
        return false;
      }
      return true;
  }
  
  
  struct TrieNode* remove(TrieNode* root, string key, int depth) {
        if(!root)
          return NULL;
        if(depth == key.size()) {
          if(root->eof) {
              root->eof = false;
            }
          if(isEmpty(root)) {
            delete(root);
            root = NULL;
            }
            
            return root;
         }
         int ind = key[depth] - 'a';
         root->child[ind] = remove(root->child[ind], key, depth + 1);
         
         if(isEmpty(root) && root->eof == false) {
          delete(root);
          root = NULL;
          }
          
          return root;
  }
  
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
     cout<<endl;
     remove(root, "the", 0);
    searchrec(root, "the")? cout<<"Yes\n" : cout<<"No"<<endl;
     
     
    return 0;
    }
  
