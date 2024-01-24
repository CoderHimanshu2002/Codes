class Solution
{
    void insertAtTail(Node *&head,Node *&tail,int d)
    {
        Node *nodeToInsert=new Node(d);
        if(head==NULL)
        {
         head=nodeToInsert;
         tail=nodeToInsert;
        }
        else
        {
         tail->next=nodeToInsert;
         tail=nodeToInsert;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node *cloneHead=NULL;
        Node *cloneTail=NULL;
        
        Node *temp=head;
        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->data);
            temp=temp->next;
        }
        Node *originalNode=head;
        Node *cloneNode=cloneHead;
        
        while(originalNode!=NULL && cloneNode!=NULL)
        {
            Node *next=originalNode->next;
            originalNode->next=cloneNode;
            originalNode=next;
            
            next=cloneNode->next;
            cloneNode->next=originalNode;
            cloneNode=next;
        }
        
        temp=head;
        
        while(temp!=NULL)
        {
          if(temp->next!=NULL)
          {
            temp->next->arb=temp->arb ? temp->arb->next :temp->arb;
          }
          
          temp=temp->next->next;
        }
        
        originalNode=head;
        cloneNode=cloneHead;
        
         while(originalNode!=NULL && cloneNode!=NULL)
        {
          originalNode->next=cloneNode->next;
          originalNode=originalNode->next;
          
          if(originalNode!=NULL)
          cloneNode->next=originalNode->next;
          
          cloneNode=cloneNode->next;
        }
        
        return cloneHead;
        
    }

};
