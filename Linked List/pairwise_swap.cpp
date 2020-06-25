//Question https://practice.geeksforgeeks.org/problems/pairwise-swap-elements-of-a-linked-list-by-swapping-data/1
Node* pairWiseSwap(struct Node* head) {
    Node* tmp = head;
    while(tmp && tmp->next) {
        int t = tmp->data;
        tmp->data = tmp->next->data;
        tmp->next->data = t;
        tmp = tmp->next->next;
    }
    return head;
    // The task is to complete this method
}
