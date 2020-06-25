// Question https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
Node* addTwoLists(Node* first, Node* second) {
    Node* head1 = first;
    Node* head2 = second;
    Node* k = new Node(-1);
    Node* res = k; 
    int carry = 0;
    while(head1 || head2) {
        int h1 = 0;
        int h2 = 0;
        if(head1) h1 = head1->data;
        if(head2) h2 = head2->data;
        int sum = carry + h1 + h2;
        carry = sum >= 10 ? 1 : 0;
        sum = sum % 10;
        Node* t = new Node(sum);
        cout<<h1<<" "<<h2<<" "<<sum<<endl;
        res->next = t;
        res = res->next;
        if(head1) head1 = head1->next;
        if(head2) head2 = head2->next;
    }
    if(carry == 1) {
        Node *t = new Node(carry);
        res->next = t;
        res = res->next;
    }
    return k->next;
}
