//https://leetcode.com/problems/valid-anagram/submissions/

class Solution {
public:
    bool isAnagram(string s, string t) {
        int flag = 0;
        if(s.size() != t.size()) {
            return false;
        }
        int has[26]  = {0};
        for(int i = 0; i < s.size(); i++) {
            has[s[i] - 'a']++;
        }
        for(int i = 0; i < t.size(); i++) {
            has[t[i] - 'a']--;
            if(has[t[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
