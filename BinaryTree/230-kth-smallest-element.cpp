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
//inorder traversal return values in ascending order 
    int solver(TreeNode* root, int k,int& count){
        
        if(root == NULL){
            return -1;
        }   

        //stores the answer for left subtree 
        int result = solver(root->left,k,count);
        
        if(result != -1)return result;

        //keeping count to stop at the kth element and avoid unnecessary recursion 
        count++;
        if(count == k){
            return root->val;
        }

        //if not found in left subtree we return answer from right subtree
        return solver(root->right,k,count);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return solver(root,k,count);
    }
};