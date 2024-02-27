vector<int> inorderTraversal(TreeNode* root) {

        vector<int> inOrder;
        stack<TreeNode*> s;
        while (true) {
            if (root != NULL) {
                s.push(root);
                root = root->left;
            }
            else 
            {
              if (s.empty())
              break;
                root = s.top();
                inOrder.push_back(root->val);
                s.pop();
                root = root->right;
            }
        }
        return inOrder;
    }
