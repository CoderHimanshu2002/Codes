int compare(Node *list1, Node *list2) 
{
  Node *temp1=list1;
  Node *temp2=list2;
  
  while(temp1 && temp2){
      if(temp1->c!=temp2->c){
          if(temp1->c > temp2->c)
          return 1;
          else
          return -1;
      }
      temp1=temp1->next;
      temp2=temp2->next;
      }
      
    return 0;
  
}
