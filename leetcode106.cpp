class Solution {
    int postIndex;

public:
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, unordered_map<int,int>& inMap) {
        if(inStart > inEnd) return nullptr;

        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        int inIndex = inMap[rootVal];

        // IMPORTANT: build right subtree first
        root->right = buildTreeHelper(inorder, postorder, inIndex + 1, inEnd, inMap);
        root->left  = buildTreeHelper(inorder, postorder, inStart, inIndex - 1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        postIndex = postorder.size() - 1;
        unordered_map<int,int> inMap;
        for(int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTreeHelper(inorder, postorder, 0, inorder.size() - 1, inMap);
    }
};
