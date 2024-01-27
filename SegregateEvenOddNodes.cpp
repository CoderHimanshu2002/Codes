void insert(Node *&head,Node *&tail,int d)
    {   

       //function to insert nodes in even or odd lists...

        Node *newNode=new Node(d);
        if(head==NULL)
        {
            head=newNode;
            tail=newNode;
        }
        else
        {
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* divide(int N, Node *head)
    {
        // code here
        Node *even=new Node(-1);
        Node *evenTail=even;


        Node *odd=new Node(-1);
        Node *oddTail=odd;
       
        Node *temp=head;
        while(temp!=NULL)
        {

            //if data is even insert in even list....
            if((temp->data)%2==0)
            {
              insert(even,evenTail,temp->data);
            }

           //if data is odd insert in odd list...
            else
            {
               insert(odd,oddTail,temp->data);
            }
            
            temp=temp->next;
        }
        

        //finally merge the two lists....


        Node *curr=even;
        while(curr->next!=NULL)
        {
          curr=curr->next;
        }
        curr->next=odd->next;
         

        // return the main head...
        return even->next;
    }

