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
     
    bool solver(TreeNode* root,int target){
       if(root == NULL){
           return false;
       }
       
       
       
       target = target - root->val;
       
       if(root->left == NULL && root->right == NULL){
           return target == 0;
       }
       
       
       return solver(root->left,target) || solver(root->right,target);
       
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
       return solver(root,targetSum);
       
       
    }
};