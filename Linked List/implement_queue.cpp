//Question https://practice.geeksforgeeks.org/problems/implement-queue-using-linked-list/1
/* The method push to push element into the queue*/
void MyQueue:: push(int x)
{
    QueueNode* t = new QueueNode(x);
    if(!front) {
        front = rear = t;
        return;
    }
    rear->next = t;
    rear = rear->next;
        // Your Code
}

/*The method pop which return the element
  poped out of the queue*/
int MyQueue :: pop()
{
    if(!front)
        return -1;
    else {
        int x = front->data;
        front = front->next;
        return x;
        
    }
        // Your Code       
}
