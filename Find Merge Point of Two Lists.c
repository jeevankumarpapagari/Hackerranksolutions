// Complete the findMergeNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    int l1 = 0,l2 = 0;
    SinglyLinkedListNode *temp;
    for(temp=head1;temp;temp=temp->next)
        l1++;
    for(temp=head2;temp;temp=temp->next)
        l2++;
    while(l1 > l2)
    {
        head1 = head1->next;
        l1--;
    }
    while(l2 > l1)
    {
        head2 = head2->next;
        l2--;
    }
    while(head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1->data;
}
