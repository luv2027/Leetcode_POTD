class Solution {
public:
    vector<vector<int>> ans;
    int s1, e1; 
    int s2 = 0;
    int e2 = 0;

    bool is_valid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }

    void rec(int i, int j, int n, int m, vector<vector<int>> &land){
        s2 = max(s2, i);
        e2 = max(e2, j);

        land[i][j] = 0;
        if(is_valid(i+1, j, n, m) && land[i+1][j] == 1){
            rec(i+1, j, n, m, land);
        }

        if(is_valid(i, j+1, n, m) && land[i][j+1] == 1){
            rec(i, j+1, n, m, land);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1){
                    s1 = i;
                    e1 = j;
                    rec(i, j, n, m, land);
                    ans.push_back({s1, e1, s2, e2});
                    s2 = 0;
                    e2 = 0;
                }
            }
        }
        return ans;
    }
};