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
    vector<int> iterativePreorder(TreeNode* root) {
        vector<int> preorder;
        if(root == nullptr) {
            return preorder;
        }
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()) {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right != nullptr) {
                st.push(root->right);
            }
            if(root->left != nullptr) {
                st.push(root->left);
            }
        }
        return preorder;
    }

    // space: O(N) using 2 stack
    vector<int> iterativePostorder(Node* root) {
        vector<int> res;
        if (!root) return res;

        // st1 to store the nodes in process
        // and st2 is to store the postorder sequence
        stack<Node*> s1, s2;
        s1.push(root);
    
        while (!s1.empty()) {
            Node* node = s1.top();
            s1.pop();
            s2.push(node);
            if (node->left) s1.push(node->left);
            if (node->right) s1.push(node->right);
        }
        
        while (!s2.empty()) { // it is the postorder
            res.push_back(s2.top()->val);
            s2.pop();
        }
        return res;
    }

    vector<int> traverse(TreeNode* root) {
        vector<int> ans;
        inorderTraverse(root,ans);
        return ans;
    }
};
