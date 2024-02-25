vector <int> zigZagTraversal(Node* root)
    {
        // Code here
        vector<int> ans;
        
        if(root==NULL){
            return ans;
        }
        bool leftToRight=true;
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty()){
            
            int size=q.size();
            vector<int> res(size);
            
            for(int i=0;i<size;i++){
                
                Node *frontNode=q.front();
                
                q.pop();
                
                int index= leftToRight ? i:size-i-1;
                res[index]=frontNode->data;
                
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            leftToRight=!leftToRight;
            
            for(auto i:res){
                ans.push_back(i);
            }
            
        }
        
        return ans;
