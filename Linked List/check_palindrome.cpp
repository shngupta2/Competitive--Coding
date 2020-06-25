//Question https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
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
bool isPalindrome(Node *head)
{
    
    Node * slow = head;
    Node * fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    slow = reverseList(slow);
    while(slow) {
        if(slow->data != fast->data) 
            return false;
        slow = slow->next;
        fast = fast->next;

    }

    return true;
    //Your code here
}
