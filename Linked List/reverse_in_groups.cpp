//Question https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

struct node *reverse (struct node *head, int k)
{ 
    node* curr = head;
    node* prev = NULL;
    node* next;
    int counter = k;
    while(counter-- && curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    if(head) {
   //     cout<<head->data<<endl;
    head->next = reverse(next, k);
    }
    return prev;
    // Complete this method
}
