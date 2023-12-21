int countNodesinLoop(struct Node *head)
{
    // Code here
        Node* fast = head;
        Node* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                slow = slow->next;
                int i=1;
                while(slow!=fast){
                    i++;
                }
                return i;
            }
        }
        return 0;
}