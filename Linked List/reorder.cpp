//Question https://leetcode.com/problems/reorder-list/
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
    ListNode* reversel(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        return prev;
        
    }
    void reorderList(ListNode* head) {
            if(!head || !head->next)
                return;
        //head of 2nd half
        ListNode* slow = head;
        //head of 1st half
        ListNode* l1 = slow;
        //tail of 2nd half
        ListNode* fast = head;
        //taail of first half
        ListNode* prev = NULL;
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // make end of first ll NULL
        prev->next = NULL;
        ListNode* l2 = reversel(slow);
        
    
   // void merge(ListNode* l1, ListNode* l2) {
        while(l1) {
            ListNode* l1_next = l1->next;
            ListNode* l2_next = l2->next;
            l1->next = l2;
            if(!l1_next)
                break;
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
};
