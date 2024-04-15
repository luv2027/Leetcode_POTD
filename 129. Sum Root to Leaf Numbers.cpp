class Solution {
public:

    int s = 0;
    void rec(TreeNode* root, int curr_sum){
        curr_sum = curr_sum*10 + root -> val;
        
        if(root -> left == NULL && root -> right == NULL){
            s += curr_sum; 
            return;
        }

        if(root -> left != NULL){
            rec(root -> left, curr_sum);
        }

        if(root -> right != NULL){
            rec(root -> right, curr_sum);
        }
    }

    int sumNumbers(TreeNode* root) {
        rec(root, 0);
        return s;
    }
};