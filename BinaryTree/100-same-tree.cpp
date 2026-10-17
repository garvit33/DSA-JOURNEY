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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //checks if both pointers are null and return true 
        if(p == NULL && q == NULL){
            return true;
        }

        //if only one pointer is null
        if(p == NULL || q == NULL){
            return false;
        }

        //if not null then check values of both pointers 
        if(p->val != q->val){
            return false;
        }
        
        //recursive call for left and right side for both pointers
        return isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
};