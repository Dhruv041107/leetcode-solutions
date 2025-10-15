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
    void inorder(TreeNode* root,vector<int>&ans){
        if(!root)   return;

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool checkSum(vector<int>ans,int &k){
        int s=0;
        int e=ans.size()-1;
        int sum=0;
        while(s<e){
            sum=ans[s]+ans[e];
            if(sum==k){
                return true;
            }
            else if(sum<k){
                s++;
            }
            else if(sum>k){
                e--;
            }
        }
        return false;

    }


    bool findTarget(TreeNode* root, int k) {
        vector<int>ans;
        inorder(root,ans);
        return checkSum(ans,k);
    }
};