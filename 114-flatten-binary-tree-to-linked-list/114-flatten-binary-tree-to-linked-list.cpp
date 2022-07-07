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
    void preorder(vector<int>&pre,TreeNode* node){
        if(node==NULL)return;
        pre.push_back(node->val);
        preorder(pre,node->left);
        preorder(pre,node->right);
    }
    void flatten(TreeNode* root) {
        if(root==NULL)return ;
        
        vector<int>pre;
        preorder(pre,root);
        
        root->left = NULL;
        for(int i = 1;i<pre.size();i++){
            root->left = NULL;
            if(root->right==NULL){
                root->right = new TreeNode(pre[i]);
                
            }
            else{
                root->right->val = pre[i];
            }
            root = root->right;
        }
    }
};