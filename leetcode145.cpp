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



 void  postorder(TreeNode* root,vector<int> & order){

    if(root  == NULL){

        return ;
    }

  postorder(root->left,order);

  postorder(root->right , order);

  order.push_back(root->val);

 }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>order;

        postorder(root,order);

        return order;


        
    }
};
