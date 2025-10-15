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
    int BSTMax(TreeNode* root){
        if(!root)   return 0;

        while(root->right){
            root=root->right;
        }
        return root->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return NULL;

        if(root->val == key){
            if(root->left ==NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            else if(root->left !=NULL && root->right == NULL){
                TreeNode* leftchild=root->left;
                root->left=NULL;
                delete root;
                return leftchild;
            }
            else if(root->left ==NULL && root->right != NULL){
                TreeNode* rightchild=root->right;
                root->right=NULL;
                delete root;
                return rightchild;
            }
            else if(root->left !=NULL && root->right != NULL){
                
                int leftsidemaxelement=BSTMax(root->left);

                root->val=leftsidemaxelement;

                root->left=deleteNode(root->left,leftsidemaxelement);
            }

        }
        else{
            if(key < root->val){
                root->left=deleteNode(root->left,key);
            }
            else{
                root->right=deleteNode(root->right,key);
            }
        }

        return root;


    }
};