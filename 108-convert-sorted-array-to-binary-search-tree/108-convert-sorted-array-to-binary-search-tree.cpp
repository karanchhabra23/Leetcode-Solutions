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
    TreeNode* build(int i , int j, vector<int>&a){
        if(i>j)return NULL;
        int mid = (i+j)/2;

        TreeNode* node = new TreeNode(a[mid]);
        node->left = build(i,mid-1,a);
        node->right = build(mid+1,j,a);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& a) {
            int n = a.size();
        int mid = (n-1)/2;
        TreeNode* root = new TreeNode(a[mid]);
        root->left = build(0,mid-1,a);
        root->right = build(mid+1,n-1,a);    
        return root;
    }
};