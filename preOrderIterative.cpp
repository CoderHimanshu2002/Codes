 vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;

        if (root == NULL)
            return ans;
        
        stack<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *temp=q.top();
            q.pop();

            ans.push_back(temp->val);

            if(temp->right){
                q.push(temp->right);
            }

            if(temp->left){
                q.push(temp->left);
            }
        }

        return ans;
    }
