//Question https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
void deleteNode(Node *node)
{   
    
    while(node->next != NULL && node->next->next != NULL) {
        node->data = node->next->data;
        node = node->next;
    }
    if(node->next->next == NULL) {
        node->data = node->next->data;
        node->next = NULL;
    }
    node->next = NULL;
   // Your code here
}

