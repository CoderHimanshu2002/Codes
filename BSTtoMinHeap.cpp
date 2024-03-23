//Function to store the inorder of the given BST...
void inorder(BinaryTreeNode *root,vector<int> &ans){

	if(root==NULL){
		return ;
	}

	else{
		inorder(root->left,ans);
		ans.push_back(root->data);
		inorder(root->right,ans);
	}
}

//Update the given tree in Min Heap form using preorder of the inorder traverse of the BST...
void preOrder(BinaryTreeNode *&root,vector<int> ans,int &index){
      if(root==NULL){
		  return;
	  }

	  root->data=ans[index++];
	  preOrder(root->left, ans, index);
	  preOrder(root->right, ans,index);
	  
}

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	// Write your code here.
	vector<int> inorderStore;

	inorder(root,inorderStore);
    
	int index=0;
	preOrder(root,inorderStore,index);

	return root;
}
