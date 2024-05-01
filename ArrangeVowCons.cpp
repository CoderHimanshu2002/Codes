 struct Node* arrangeCV(Node* head) {
        // Code here
        Node *vowHead=NULL;
        Node *consHead=NULL;
        Node *vowTail=NULL;
        Node *consTail=NULL;
        
        Node *temp=head; 
        
        while(temp!=NULL)
        {
            if(temp->data=='a'||temp->data=='e'||temp->data=='i'||temp->data=='o'
            ||temp->data=='u'){
                Node *vowNode=new Node(temp->data);
                if(vowHead==NULL){
                    vowHead=vowNode;
                    vowTail=vowNode;
                }
                else{
                    vowTail->next=vowNode;
                    vowTail=vowNode;
                }
            }
            
            else
            {
                Node *consNode=new Node(temp->data);
                if(consHead==NULL){
                    consHead=consNode;
                    consTail=consNode;
                }
                else
                {
                    consTail->next=consNode;
                    consTail=consNode;
                }
            }
            temp=temp->next;
        }
        
        if(vowHead==NULL){
            return consHead;
        }
        
        vowTail->next=consHead;
        
        return vowHead;
        
    }
