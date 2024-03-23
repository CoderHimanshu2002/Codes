//Function to count the number of nodes present in the given Binary Tree...
int countNode(struct Node *tree){
        
        if(tree==NULL){
            return 0;
        }
        
        int ans=1+countNode(tree->left)+countNode(tree->right);
        
        return (ans);
    }

//Function to find whether the given Binary Tree is a Complete Binary tree or not...
    bool isCBT(struct Node *tree,int i,int nodeCount){
        
        if(tree==NULL){
            return true;
        }
        
        if(i >= nodeCount){
            return false;
        }
        
        else{
            bool left=isCBT(tree->left,2*i+1,nodeCount);
            bool right=isCBT(tree->right,2*i+2,nodeCount);
            
            return (left && right);
        }
    }

    //Function to check whether the CBT is following the order of Heap or not i.e MaxHeap or MinHeap...
    bool maxOrder(struct Node *root){
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        if(root->right==NULL){
            
            return root->data > root->left->data;
        }
        
        else
        {
            bool left=maxOrder(root->left);
            bool right=maxOrder(root->right);
            return (root->data > root->left->data && root->data > root->right->data && left && right);
        }
    }

//Function to check that a given binary tree is a heap or not...?
    bool isHeap(struct Node* tree) {
        // code here
        int nodeCount=countNode(tree);
        
        if(isCBT(tree,0,nodeCount) && maxOrder(tree)){
            return true;
        }
        
        else
        {
            return false;
        }
    }
