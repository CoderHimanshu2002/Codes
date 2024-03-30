/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class compare{
  public:
  
  bool operator()(ListNode *a,ListNode *b){
      return a->val > b->val;
  }  
};

 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
   
   priority_queue<ListNode *,vector<ListNode *>,compare> minHeap;
   int k=A.size();
   if(k==0)
   return NULL;
   
   ListNode *head=NULL;
   ListNode *tail=NULL;
   
   //step 1: insert first node of k LLs...
   for(int i=0;i<k;i++){
       if(A[i]!=NULL){
           minHeap.push(A[i]);
       }
   }
   
   //step 2:
   while(minHeap.size() > 0){
       
       ListNode *top=minHeap.top();
       minHeap.pop();
       
       if(top->next!=NULL){
           minHeap.push(top->next);
       }
       
       if(head==NULL){
           head=top;
           tail=top;
       }
       
       else{
           tail->next=top;
           tail=top;
       }       
   }
   
   return head;
}
