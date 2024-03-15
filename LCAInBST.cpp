//APPROACH 1-: (Recursive Way)...
TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
{
    // Write your code here.
    if(root==NULL){
        return NULL;
    }

    if(root->data > P->data && root->data > Q->data){  //If P->data and Q->data is less than root->data go to left Subtree...
       return  LCAinaBST(root->left,P, Q);
    }

    if(root->data < P->data && root->data < Q->data){  //If P->data and Q->data is greater than root->data go to right Subtree...
        return LCAinaBST(root->right,P, Q);
    }

    return root; // Else the root will be the LCA of P and Q...
}

// APPROACH 2 -: (Iterative Way)...
while(root){

        if(root->data > P->data && root->data > Q->data)
        root=root->left;

        if(root->data < P->data && root->data < Q->data)
        root=root->right;

        else
        return root;
    }
