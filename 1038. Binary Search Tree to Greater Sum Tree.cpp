class Solution {
public: 
    int s = 0;
    void dfs(TreeNode *root){
        if(root == NULL) return;
        s += root -> val;
        dfs(root -> left);
        dfs(root -> right);
    }

    int smaller_sum = 0;
    void change(TreeNode *root){
        if(root == NULL) return;
        if(root -> left) change(root -> left);
        int temp = root -> val;
        root -> val = s - smaller_sum;
        smaller_sum += temp;
        if(root -> right) change(root -> right);
    }

    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        change(root);
        return root;   
    }
};