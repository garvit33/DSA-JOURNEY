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
    int maxDepth(TreeNode* root) {
        //if nodes are null we return 0 and exit the loop ; 
        if(root == NULL){
            return 0;
        }

        //it loops recursively and add one for each child node in left and right which is passed as root node in the recursion function 
        int leftdep = maxDepth(root->left);
        int rightdep = maxDepth(root->right);
        
        //chooses the bigger depth side and 1 for its own at a certain root pointer 
        return max(leftdep,rightdep)+1;
    }
};
