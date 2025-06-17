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
    // space: O(1)
    // time: O(2*N)
    vector<int> morrisInorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *cur = root;
        while(cur!=NULL){
            // if left is null take the ele and go to right
            if(cur->left==NULL){
                ans.push_back(cur->val);
                cur = cur->right;
            }
            // else you have to do the thread thing
            else{
                // go to the rightest to the left of current
                TreeNode *pre = cur->left;
                while(pre->right and pre->right != cur){
                    pre = pre->right;
                }
                // if rightest is not connected through the thread to cur connect it
                // and go to left;
                if(pre->right==NULL){
                    pre->right = cur;
                    cur = cur->left;
                }
                // otherwise we have already connected it its time to remove back and put the 
                // ele in the ans and go to right
                else{
                    pre->right = NULL;
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return ans;
    }
    // space: O(N)
    vector<int> iterativeInorder(TreeNode* root){
        TreeNode* curr = root;
        stack<TreeNode*> s
        while(curr || !s.empty()) {
            while(curr) {
                s.push(curr);
                curr = curr->left;
            }
            ans.push_back(s.top()->val);
            curr = s.top();
            s.pop();
            curr = curr->right;
        }
    }

    vector<int> traverse(TreeNode* root) {
        vector<int> ans;
        inorderTraverse(root,ans);
        return ans;
    }
};
