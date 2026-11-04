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
    //search function for roots in preorder
    int search(vector<int>& inorder,int val,int left,int right){
        for(int i = left;i<=right;i++){
            if(inorder[i]==val){
                return i;
            }
        }

        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,int& preidx,int left,int right){
        //if idx goes out of range
        if(left>right){
            return NULL;
        }
       //creating nodes 
        TreeNode* root = new TreeNode(preorder[preidx]);
        //ssearching root in inorder
        int inindex = search(inorder,preorder[preidx],left,right);
        preidx++;

        //creating nodes on the left and right in given range from inindexx
        root->left = helper(preorder,inorder,preidx,left,inindex-1);
        root->right = helper(preorder,inorder,preidx,inindex+1,right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        return helper(preorder,inorder,preidx,0,preorder.size()-1);
    }
};