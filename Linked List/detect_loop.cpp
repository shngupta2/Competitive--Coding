//Question https://practice.geeksforgeeks.org/problems/detect-loop-in-linked-list/1
int detectloop(Node *head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow)
            return 1;
    }
    return 0;
    // your code here
}
