//Store Inorder of the given BST...
void inorderTraversal(BinaryTreeNode<int>* root, vector<int> &ans){
    if(root==NULL){
        return;
    }

    else
    {
      inorderTraversal(root->left, ans);
      ans.push_back(root->data);
      inorderTraversal(root->right, ans);
    }
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	//Write your code here
    vector<int> ans;

    inorderTraversal(root, ans);
    int i=0;
    int j=ans.size()-1;
    int sum=0;
  
    // Use two pointer to the array to check whether the pair exists in the tree or not...
    while(i < j){

        sum=ans[i]+ans[j];
        if(sum==target){
            return true;
        }

        else if(sum  > target){
            j--;
        }

        else
        {
            i++;
        }
    }
    
    return false;
}
