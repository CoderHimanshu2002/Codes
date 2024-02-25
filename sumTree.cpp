 pair<bool,int> isSumTreeFast(Node *root){
        
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        
        if(root->left==NULL && root->right==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> leftAns=isSumTreeFast(root->left);
        pair<bool,int> rightAns=isSumTreeFast(root->right);
        
        bool lAnsSum=leftAns.first;
        bool rAnsSum=rightAns.first;
        
        int lSum=leftAns.second;
        int rSum=rightAns.second;
        
        bool cond=root->data ==lSum+rSum;
        
        pair<bool,int> ans;
        
        if(lAnsSum && rAnsSum && cond)
        {
            ans.first=true;
            ans.second=root->data+lSum+rSum;
        }
        else
        {
            ans.first=false;
        }
        
        return ans;
    }
