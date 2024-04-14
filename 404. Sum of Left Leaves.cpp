
class Solution {
public:
    int s = 0;
    int f = 0;

    void solve(TreeNode* root){
        if(root -> left == NULL && root -> right == NULL && f == 1){
            s += root-> val;
            return;
        }

        f = 1;
        if(root -> left){
            solve(root -> left);
        }
        
        f=0;
        if(root -> right){
            solve(root -> right);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        solve(root);
        return s; 
    }
};