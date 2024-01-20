 ListNode *moveToFront(ListNode *head)
    {
        if(head->next==NULL)
        return head;
        
        ListNode *temp=head;
        ListNode *prev=NULL;
      
        // iterate the list till end...
        while(temp->next!=NULL)
        {
          prev=temp;
          temp=temp->next;
        }
        
        prev->next=NULL;
        //point next of last node to head...
        temp->next=head;
        // assign head at it's desired position...
        head=temp;
        
        return head;
    }
