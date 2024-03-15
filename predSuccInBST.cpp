pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode *temp=root;

    int pred=-1;
    int succ=-1;
    // Find the key in the BST and store predecessor and Successor...
    while(temp!=NULL && temp->data != key)
    {
        if(temp->data > key){
          succ=temp->data;
          temp=temp->left;
        }

        else{
            pred=temp->data;
            temp=temp->right;
        }
    }
  // If temp is not NULL , Find the predecessor from the maximum node of left Subtree and minimum node of right Subtree...
   if(temp)
   {
    TreeNode  *leftTree=temp->left;

    while(leftTree != NULL){
      pred=leftTree->data;
      leftTree=leftTree->right;
    }

    TreeNode  *rightTree=temp->right;

    while (rightTree != NULL) {
      succ = rightTree->data;
      rightTree = rightTree->left;
    }
    
   }
    pair<int,int> ans=make_pair(pred,succ);

    return ans;
}
