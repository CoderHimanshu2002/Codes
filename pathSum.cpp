/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        //int sum=0;

        if(root==NULL){
            return 0;
        }

        if(root->left==NULL && root->right==NULL){
            return targetSum==root->val;
        }
        
        bool leftSum=hasPathSum(root->left,targetSum-root->val);
        bool rightSum=hasPathSum(root->right,targetSum-root->val);

        return leftSum || rightSum;
        
    }
};
