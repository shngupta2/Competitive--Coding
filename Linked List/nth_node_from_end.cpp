// Question https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1
int getNthFromLast(Node *head, int n)
{
    Node * t= head;
    Node* b = head;
    for(int i = 0; i < n; i++) {
        if(!t) return -1;
        t = t->next;
        
    }
    while(t) {
        t = t->next;
        b = b->next;
    }
    return b->data;
       // Your code here
}
