//Question https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* t = head;
        ListNode* k = new ListNode(-1);
        ListNode* a = k;
        while(t) {
            if(t->next && t->val == t->next->val) {
                int k = t->val;
               while(t->next && k == t->next->val) {
                t->next = t->next->next;
               }
                t = t->next;

            } else {
                k->next = t;
                k = k->next;
                t = t->next;
            }
        }
        k->next = NULL;
        return a->next;
    }
};
