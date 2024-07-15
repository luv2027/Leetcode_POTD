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
    unordered_map<int, vector<pair<int,int>>> g;
    int root = -1;
    
    TreeNode* bfs(){
        queue<TreeNode*> q;
        TreeNode* root_node = new TreeNode(root);
        q.push(root_node);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            int node = temp -> val;

            for(auto v : g[node]){
                TreeNode* child_node = new TreeNode(v.first);
                    if(v.second == 1){
                        temp -> left = child_node;
                    }
                    else if(v.second == 0){
                        temp -> right = child_node;
                    }
                q.push(child_node);   
            }
        }
        return root_node;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            int u = descriptions[i][0];
            int v = descriptions[i][1];
            int is_left = descriptions[i][2];

            g[u].push_back({v, is_left});
            mp[v]++;
        }

        for(int i=0; i<n; i++){
            if(mp[descriptions[i][0]] == 0){
                root = descriptions[i][0];
            }
        }

        return bfs();
    }
};