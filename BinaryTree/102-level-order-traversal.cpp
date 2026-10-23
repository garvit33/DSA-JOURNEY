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
    queue<TreeNode*> q;
    vector<vector<int>> ans;

    void traverse(TreeNode* root){
        if(root == NULL){
            return;
        }
        q.push(root);

// while q is not empty
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            // push every element at current level 
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                //if there child are not null push them into the queue
                if(node->left != NULL){
                    q.push(node->left);
                }

                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }

    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        traverse(root);
        return ans;
    }
};