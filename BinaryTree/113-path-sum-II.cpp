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

    vector<vector<int>> ans;
    vector<int> curr;
    
    void solver(TreeNode* root,int target){
        
                
        if(root == NULL){
            return;           
           }
        
        curr.push_back(root->val);
        
        target -= root->val;
        
        if(root->left == NULL && root->right == NULL && target == 0){
            ans.push_back(curr);
        }
        
        solver(root->left,target); 
        solver(root->right,target);
        
        curr.pop_back();
          
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        solver(root,targetSum);
        
        return ans;
        
    }
};