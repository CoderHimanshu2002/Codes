//Store the inorder of the given Tree...
void inorderTraversal(TreeNode<int> *root, vector<int> &ans){

    if(root==NULL)
    return;

    else
    {
        inorderTraversal(root->left, ans);
        ans.push_back(root->data);
        inorderTraversal(root->right, ans);
    }
}


TreeNode<int>* flatten(TreeNode<int>* root)
{
    // Write your code here
    vector<int> ans;
    
    inorderTraversal(root, ans);
    TreeNode<int>* newRoot=new TreeNode<int>(ans[0]);
    TreeNode<int>* curr=newRoot;

    int n=ans.size();

    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(ans[i]);
        temp->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;
  
    return newRoot;
}
