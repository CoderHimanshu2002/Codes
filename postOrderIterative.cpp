 vector<int> postorderTraversal(TreeNode* root) {

        vector<int> ans;

        if (root == NULL)
            return ans;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while (!s1.empty()) {
            TreeNode* temp = s1.top();
            s1.pop();

            s2.push(temp);

            if (temp->left) {
                s1.push(temp->left);
            }

            if (temp->right) {
                s1.push(temp->right);
            }
        }

        while (!s2.empty()) {
            TreeNode* temp2 = s2.top();
            s2.pop();

            ans.push_back(temp2->val);
        }

        return ans;
    }

/*
Algorithm:

   1. Push root to first stack.
2. Loop while first stack is not empty
   2.1 Pop a node from first stack and push it to second stack
   2.2 Push left and right children of the popped node to first stack
3. Print contents of second stack

*/
