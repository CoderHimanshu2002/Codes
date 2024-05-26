//Recursive approach...
TreeNode *solve(TreeNode *root,int key){
         if(root==NULL){
            return NULL;
         }

         if(root->val==key){
            return root;
         }

         if(key > root->val){
            return solve(root->right,key);
         }

         if(key < root->val){
            return solve(root->left,key);
         }

         return NULL;
    }

//Iterative Approach...
    TreeNode *anotherFunc(TreeNode *root,int n){
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode *front=q.front();
            q.pop();

            if(front->val==n){
                return front;
            }

            else if(front->val < n){
                q.push(front->right);
            }

            else if(front->val >n){
                q.push(front->left);
            }
        }

        return NULL;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        
        return solve(root,val);
    }
