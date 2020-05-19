/*
 *here you can see program for finding prefix for strings.
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
  
// iterative insertion start  
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
 // iterative insertion end

//recursive insertion start
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
 
  
  void insertrecur(struct TrieNode* root, string key) {
      insertRecursive(root, key, 0);
  }
// recursive insertion end
  
int count(TrieNode *root, int *index) {
    int count = 0;
    for(int i = 0; i < 26; i++) {
        if(root->child[i] != NULL) {
            count++;
            *index = i;
        }
    }
    return count;
}
string pre(TrieNode * root) {
    
    struct TrieNode *p = root;
    int index;
    string prefix = "";
    while((count(p, &index) == 1) && (p->eof == false)) {
        p = p->child[index];
        prefix += 'a' + index;
    }
    
    return prefix;
}

  
  int main() {
    struct TrieNode * root = getNode();
    string keys[] = {"the", "a", "hi", "hello", "there", "answer", "no", "bye", "their"};
    int n = sizeof(keys)/ sizeof(keys[0]);
    for(int i = 0; i < n; i++) 
      insert(root, keys[i]);
    cout<<pre(root);
    return 0;
    }
  
