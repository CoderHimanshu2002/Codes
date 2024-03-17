void inorder(TreeNode<int> *root,vector<int> &a){
    if(root==NULL)
    return;

    inorder(root->left,a);
    a.push_back(root->val);
    inorder(root->right,a);
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here
    vector<int> a;

    inorder(root,a);

    for(int i=a.size()-1; i>=0;i--){
        if(a[i] <= X)
        return a[i];
    }

    return -1;
}
