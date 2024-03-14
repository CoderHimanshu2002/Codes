// Firstly push the inorder Traversal of the Given BST in a vector...
void inorderTraversal(TreeNode *root,vector<int> &v){
        if(root==NULL){
           return;
        }

        inorderTraversal(root->left,v);
        v.push_back(root->val);
        inorderTraversal(root->right,v);
    }

    bool isValidBST(TreeNode* root) {
        
        if(root==NULL){
            return true;
        }

        vector<int> v;
        inorderTraversal(root,v);
// Check if the inorder traversal of the BST is sorted or not...
        for(int i=0;i<v.size()-1;i++){
           if(v[i]>=v[i+1]){
            return false;
           }
        }

        return true;
    }
