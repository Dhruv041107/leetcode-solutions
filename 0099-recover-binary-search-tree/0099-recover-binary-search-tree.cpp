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
    TreeNode*F,*S,*prev=0;
    void inorder(TreeNode*curr){
        if(!curr)   return;

        inorder(curr->left);
        if(prev && prev->val > curr->val){
            if(!F){
                F=prev;
            }
            S=curr;
        }
        prev=curr;

        inorder(curr->right);
    }
public:
    void recoverTree(TreeNode* root){
        inorder(root);
        if(F && S){
            swap(F->val,S->val);
        }
    }
};