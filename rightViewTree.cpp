 void func(Node *root,vector<int> &ans,int level){
        if(root==NULL)
        return ;
        
        if(level==ans.size()){
            ans.push_back(root->data);
        }
        
        func(root->right,ans,level+1);
        func(root->left,ans,level+1);
    }
    
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
       func(root,ans,0);
       
       return ans;
    }
