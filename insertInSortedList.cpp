Node *sortedInsert(struct Node* head, int data) 
    {
        // Code here
        Node *newNode=new Node(data);
        if(data < head->data)
        {
           newNode->next=head;
           head=newNode;
           
           return head;
        }
        
        if(head->next==NULL && data > head->data)
        {
            head->next=newNode;
            return head;
        }
        
        Node *temp=head;
        Node *next1=temp->next;
        while(temp->next!=NULL)
        {
            if((data >= temp->data) && (data <= next1->data))
            {
                temp->next=newNode;
                newNode->next=next1;
                
                return head;
            }
            else
            {
                if(next1->next==NULL)
                {
                    next1->next=newNode;
                    return head;
                }
                temp=temp->next;
                next1=next1->next;
            }
        }
    }
