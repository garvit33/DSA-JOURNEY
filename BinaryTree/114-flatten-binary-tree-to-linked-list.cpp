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

    TreeNode* lastnode = NULL;
    void flatten(TreeNode* root) {

        if(root == NULL){
            return;
        }


        //visits right subtree then left
        flatten(root->right);
        flatten(root->left);

        // assigns null toleft node of root
        root->left = NULL;
        //assign last visited node valuw to the right of root 
        root->right = lastnode;
        //lastnode value is updated with root to attatch the next root
        lastnode = root;
    }
};