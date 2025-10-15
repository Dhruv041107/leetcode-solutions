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
    void inorder(TreeNode*root,int&element,int &k){
        if(!root)   return;

        inorder(root->left,element,k);
        // ans.push_back(root->val);
        k--;
        if(k==0){
            element=root->val;
        }
        inorder(root->right,element,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        // vector<int>ans;
        int element=0;
        inorder(root,element,k);

        return element;    
    }
};