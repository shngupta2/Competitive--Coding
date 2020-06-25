//Question https://practice.geeksforgeeks.org/problems/rotate-a-linked-list/1
Node* rotate(Node* head, int k) {
    if(k == 0)
        return head;
    Node * curr = head;
    int count = 1;
    while(count < k && curr != NULL) {
        count++;
        curr = curr->next;
    }
    if(curr == NULL) {
        return head;
    }
    Node * kth = curr;
    while(curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head;
    head = kth->next;
    kth->next = NULL;
    return head;
}
