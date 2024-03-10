 int findPosition(int in[],int startIndex,int element,int n){
        
        for(int i=startIndex;i<n;i++){
            if(in[i]==element){
                return i;
            }
        }
        
        return -1;
    }
    
    Node *solve(int in[],int pre[],int &index,int startIndex,int endIndex,int n){
        
        if(index >=n || startIndex > endIndex ){
            return NULL;
        }
        
        int element=pre[index++];
        Node *root=new Node(element);
        
        int pos=findPosition(in,startIndex,element,n);
        
        root->left=solve(in,pre,index,startIndex,pos-1,n);
        root->right=solve(in,pre,index,pos+1,endIndex,n);
        
        return root;
    }
    
    public:
    
    Node* buildTree(int in[],int pre[], int n)
    {
        int preIndex=0;
        Node *ans=solve(in,pre,preIndex,0,n-1,n);
        
        return ans;
    }
