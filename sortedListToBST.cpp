//Make the mid of the array as root and make recursive calls for left and right parts...
TreeNode<int> *listToBST(int s,int e,vector<int> &ans){

    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;

    TreeNode<int> *newRoot=new TreeNode<int>(ans[mid]);
    newRoot->left=listToBST(s,mid-1,ans);
    newRoot->right=listToBST(mid+1, e, ans);

    return newRoot;
}

TreeNode<int>* sortedListToBST(Node<int>* head) 
{
	// Write your code here.
    vector<int> v;
    Node<int> *temp=head;
    TreeNode<int>* root=NULL;
    while(temp){
        v.push_back(temp->data);
        temp=temp->next;
    }

    return listToBST(0,v.size()-1,v);
}
