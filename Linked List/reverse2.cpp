//Question https://leetcode.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(m > 1) {
            prev = curr;
            curr = curr->next;
            m--;
            n--;
        }
        ListNode* conn = prev;
        ListNode* tail = curr;
        while(n > 0) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
            n--;
        }
        if(conn) {
            conn->next = prev;
        } else {
            head = prev;
        }
        tail->next = curr;
        return head;
    }
};
