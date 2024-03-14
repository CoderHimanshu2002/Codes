//APPROACH 1-: 
// Get Inorder Traversal of the BST and store it in a vector...
void inorderTraversal(BinaryTreeNode<int> *root,vector<int> &v){
        if(root==NULL){
           return;
        }

        inorderTraversal(root->left,v);
        v.push_back(root->data);
        inorderTraversal(root->right,v);
    }

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    vector<int> v;

    inorderTraversal(root,v);
    
    if(k>v.size()){ // if the kth smallest element doesn't exists then return -1...
        return -1;
    }
    return v[k-1]; // return the kth smallest element of the BST from the array...
}

// APPRAOCH 2-:

int solve(BinaryTreeNode<int>* root,int k,int &i){

    if(root==NULL){
           return -1;
        }
        
    int left=solve(root->left, k,i);
    if(left!=-1){
        return left;
    }
    i++;    
    if(k==i){
        return root->data;
    }
    
    return solve(root->right,k,i);
}
int kthSmallest(BinaryTreeNode<int>* root, int k) {
    // Write your code here.
    int i=0;
    int ans=solve(root,k,i);
    return ans;
}
