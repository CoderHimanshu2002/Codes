 struct Node* reverse(struct Node* first)
     {
         Node *curr=first;
         Node *prev=NULL;
         Node *forw=NULL;
         
         while(curr!=NULL)
         {
             forw=curr->next;
             curr->next=prev;
             prev=curr;
             curr=forw;
         }
         return prev;
     }
    
    void insertAtTail(struct Node *&head,struct Node *&tail,int d)
    {
        Node *temp=new Node(d);
        if(head==NULL)
        {
          head=temp; 
          tail=temp;
          return;
        }
        else
        {
          tail->next=temp;
          tail=temp;
        }
    }

     struct Node* addNum(struct Node* first, struct Node* second)
     {
         int carry=0;

         Node *ansHead=NULL;
         Node *ansTail=NULL;
         
         while(first!=NULL || second!=NULL ||carry!=0)
         {
            int val1=0;
            if(first!=NULL)
            val1=first->data;
            
            int val2=0;
            if(second!=NULL)
            val2=second->data;
             
           int sum=carry+val1+val2;
           int digit=sum%10;
           insertAtTail(ansHead,ansTail,digit);
           carry=sum/10;
           
           if(first!=NULL)
           first=first->next;
           
           if(second!=NULL)
           second=second->next;
         }
         return ansHead;
     }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        
        Node *add=addNum(first,second);
        
        Node *ans=reverse(add);
        
        return ans;
    }
