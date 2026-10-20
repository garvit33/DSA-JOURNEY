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
    vector<int> ans;

    void traverse(TreeNode* root){
        if(root==NULL){
            return;
        }
        //pushes the current nodes value 
        ans.push_back(root->val);
        // travels right side of the tree including right side of the child nodes
        traverse(root->left);
        
        // travels left side of the tree including left side of the child nodes
        traverse(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        traverse(root);

        return ans;
    }
};