//Store inorder Traversal of the given BST...
void inorderTraversal(TreeNode *root,vector<int> &ans){

    if(root==NULL)
    return;

    inorderTraversal(root->left,ans);
    ans.push_back(root->data);
    inorderTraversal(root->right,ans);
}

//Merge the two Arrays ...
vector<int> mergeTwoBST(vector<int> &a,vector<int> &b){

    vector<int> ans(a.size()+b.size());
    int i=0;
    int j=0;
    int k=0;

    while(i<a.size() && j<b.size()){
            if(a[i] < b[j]){
                ans[k++]=a[i];
                i++;
            }

            else
            {
                ans[k++]=b[j];
                j++;
            }
    }

    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }

    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    vector<int> a;
    vector<int> b;

    inorderTraversal(root1,a);
    inorderTraversal(root2,b);

    return mergeTwoBST(a,b);
}
