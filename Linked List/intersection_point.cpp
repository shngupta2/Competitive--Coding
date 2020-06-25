// Question https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1/

#include <bits/stdc++.h>
int intersectPoint(Node* head1, Node* head2)
{
    unordered_map <Node*, int> m;
    while(head1 != NULL) {
        m[head1] = 1;
        head1 = head1->next;
    }
    while(head2 != NULL) {
        if(m[head2] == 1)
            return head2->data;
        else
            m[head2] = 1;
        head2 = head2->next;
    }
    return -1;
    // Your Code Here
}
