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
int maxval = -1;
int ans=0;


 void solve(TreeNode* root,int count){

    if(!root) return ;

     if(count>maxval){
       maxval= count;
       ans= root->val;
     }

    solve(root->left,count+1);

    solve(root->right,count+1);
 }

    int findBottomLeftValue(TreeNode* root) {
        
        solve(root,0);

        return ans;
        
    }
};
