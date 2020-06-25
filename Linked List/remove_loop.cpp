//Question https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1
void removeLoop(Node* head)
{
     Node* slow = head;
    Node* fast = head->next;
    while(slow != fast) {
        if(!fast || !fast->next)
            return;
        fast = fast->next->next;
        slow = slow->next;
        
    }
       fast = fast->next;
        int size = 1;
        
        while(slow != fast) {
            size++;
            fast = fast->next;
        }
        slow = head;
        fast = head;
        for(int i = 0; i < size - 1; i++) {
            fast = fast->next;
        }
        while(slow != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        fast->next = NULL;
    
    // code here
    // just remove the loop without losing any nodes
}
