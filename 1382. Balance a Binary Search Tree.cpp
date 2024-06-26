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
    vector<int> arr;

    void rec(TreeNode* node){
        if(node == NULL) return;
        rec(node -> left);
        arr.push_back(node -> val);
        rec(node -> right);
    }

    TreeNode* buildTree(int start, int end){
        if(start > end) return NULL;
        int mid = start + (end - start)/2;

        TreeNode* node = new TreeNode(arr[mid]);
        node -> left = buildTree(start, mid-1);
        node -> right = buildTree(mid+1, end);

        return node; 
    }

    TreeNode* balanceBST(TreeNode* root) {
        rec(root);
        return buildTree(0, arr.size()-1);
    }
};