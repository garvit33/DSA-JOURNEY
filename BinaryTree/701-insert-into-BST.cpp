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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //if it reaches a null pointer create a new node with the given value
        if(root==NULL){
            return new TreeNode(val);
        }

        //if given value is smaller than the roots value than we store the recursive function of its left childs output so it makes tha chain including the given node 
        if(root->val > val){
            root->left = insertIntoBST(root->left,val); 
        }
        //if given value is greater than the roots value than we store the recursive function of its right childs output so it makes tha chain including the given node 

        else{
            root->right = insertIntoBST(root->right,val);
        }

        return root;
    }
};