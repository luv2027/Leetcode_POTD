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
    map<int, int> mp;
    vector<TreeNode*> ans;
    TreeNode* rec(TreeNode* &root){
        if(root == NULL) return NULL;

        root -> left = rec(root -> left);
        root -> right = rec(root -> right);

        if(mp[root -> val] > 0){
            if(root -> left){
                ans.push_back(root -> left);
            }

            if(root -> right){
                ans.push_back(root -> right);
            }

            delete(root);
            return NULL;
        }

        return root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(!root) return ans;

        for(int i=0; i<to_delete.size(); i++){
            mp[to_delete[i]]++;
        }

        root = rec(root);
        if(root) ans.push_back(root);
        return ans;
    }
};