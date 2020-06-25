//Question https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

Node* segregate(Node *head) {
    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    Node* tmp = head;
    while(head) {
        head->data == 0 ? n1++ : head->data == 1 ? n2++ : n3++;
        head = head->next;
    }
    head = tmp;
    while(head) {
        if(n1 > 0) {
            head->data = 0;
            n1--;
        } else if(n2 > 0) {
            head->data = 1;
            n2--;
        } else if(n3 > 0) {
            head->data = 2;
            n3--;
        }
        head = head->next;
    }
    // Add code here
    return tmp;
}
