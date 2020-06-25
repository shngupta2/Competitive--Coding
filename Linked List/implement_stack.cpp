//Question https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1

void MyStack ::push(int x) {
    StackNode* tmp = new StackNode(x);
    tmp->next = top;
    top = tmp;
}

/* The method pop which return the element
  poped out of the stack*/
int MyStack ::pop() {
    // Your Code
    if(!top)
        return -1;
    int k = top->data;
    top = top->next;
    return k;
}
