//Question https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1
Node* reverseList(Node *head)
{
    Node* prev = NULL;
    Node* curr = head;
    while(head != NULL) {
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    return prev;
  // Your code here
}

