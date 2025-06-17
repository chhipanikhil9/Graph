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
    void inorderTraverse(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        inorderTraverse(root->left,ans);
        ans.push_back(root->val);
        inorderTraverse(root->right,ans);
    }
    void postorderTraverse(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        postorderTraverse(root->left,ans);
        postorderTraverse(root->right,ans);
        ans.push_back(root->val);
    }
    void preorderTraverse(TreeNode* root,vector<int> &ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorderTraverse(root->left,ans);
        preorderTraverse(root->right,ans);
    }
    vector<int> traverse(TreeNode* root) {
        vector<int> ans;
        inorderTraverse(root,ans);
        return ans;
    }
};
