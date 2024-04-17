class Solution {
public:
    vector<string> v;
    void rec(TreeNode* root, string s){
        if(root == NULL){
            return ;
        }
        
        s += 'a' + root -> val;

        if(root -> left == NULL && root -> right == NULL){
            v.push_back(s);
            return;
        }

        rec(root -> right, s);
        rec(root -> left, s);
    }

    string smallestFromLeaf(TreeNode* root) {
        rec(root, "");
        string ans = v[0];
        reverse(ans.begin(), ans.end());

        for(int i=1; i<v.size(); i++){
            string str = v[i];
            reverse(str.begin(), str.end());
            if(str < ans){
                ans = str;
            }
        }
        return ans;    
    }
};