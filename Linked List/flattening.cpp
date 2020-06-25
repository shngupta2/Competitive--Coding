//Question https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1
Node* merge(Node* a, Node * b) {
    if(!a)
        return b;
    if(!b)
        return a;
    Node* res;
    if(a->data < b->data) {
       res = new Node(a->data);
       // res = a;
        res->next = NULL;
        res->bottom = merge(a->bottom, b);
        return res;
    } 
        else {
        res = new Node(b->data);
        //res = b;
        res->next = NULL;
        res->bottom = merge(a, b->bottom);
        return res;
    }
    
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{   Node *a =root;
    Node  *b=root->next;
    while(b!=NULL)
    {
        Node *c=b->next;
        a=merge(a,b);
        b=c;
        
    }
    return(a);
}

