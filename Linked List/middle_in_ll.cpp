// Question https://practice.geeksforgeeks.org/problems/finding-middle-element-in-a-linked-list/1

int getMiddle(Node *head)
{   int count = 1;
    if(!head)
        return -1;
    Node *tmp = head;
    while(tmp->next != NULL) {
        count += 1;
        tmp = tmp->next;
    }
    //cout<<count<<endl;
    int mid;
    if(count % 2 == 0) {
        mid = count / 2;
    } else {
        count -= 1;
        mid = count / 2;
        
    }
    
    tmp = head;
    while(tmp->next && mid != 0) {
        tmp = tmp->next;
        mid--;
    }
    if(!tmp)
        return -1;
    else 
        return tmp->data;
   // Your code here
}
