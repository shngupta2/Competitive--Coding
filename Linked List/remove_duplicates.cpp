//Question https://leetcode.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = NULL;
        p = head;
        while(p != NULL &&p->next != NULL) {
            if(p->next->val == p->val) {
                p->next = p->next->next;
            }
            else {
                p = p->next;
            }
        }
        return head;
        
    }
};
