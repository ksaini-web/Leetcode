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



void solve(TreeNode* root,int level , vector<int>& rightnode){

if(root== NULL){
    
    return ;
}

if(level == rightnode.size()){

    rightnode.push_back(root->val);
}

solve(root->right,level+1,rightnode);


solve(root->left,level+1,rightnode);





}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>rightnodes;
  
       solve(root,0,rightnodes);

       return rightnodes;


        
    }
};
