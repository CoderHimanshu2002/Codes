class Solution
{
    public:

   //Function to store inorder traversal of the tree...
    void inorder(Node *root, vector<int> &ans){
        if(root==NULL){
            return;
        }
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
    }

    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        
        inorder(root,ans);
        return ans;
    }

    //Make preorder from the stored inorder...
    Node* buildtree(vector<int>& v, vector<int>::iterator start, vector<int>::iterator end) 
    {
        if (start == end) 
        return NULL;

        auto mid = start + (end - start) / 2;
        
        Node* root = new Node(*mid);
        root->left = buildtree(v, start, mid);
        root->right = buildtree(v, mid + 1, end);
        
        return root;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
       return buildtree(A,A.begin(),A.end());
    }

};
