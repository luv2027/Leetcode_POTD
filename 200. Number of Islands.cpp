class Solution {
public:
    bool is_valid(int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m){
            return false;
        }
        return true;
    }

    void rec(int i, int j, int n, int m, vector<vector<char>>& grid){
        if(grid[i][j] == '0'){
            return;
        }

        grid[i][j] = '0';

        if(is_valid(i+1, j, n, m)){
            rec(i+1, j, n, m, grid);
        }

        if(is_valid(i-1, j, n, m)){
            rec(i-1, j, n, m, grid);
        }

        if(is_valid(i, j+1, n, m)){
            rec(i, j+1, n, m, grid);
        }

        if(is_valid(i, j-1, n, m)){
            rec(i, j-1, n, m, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    rec(i, j, n, m, grid);
                }
            }
        }
        return ans;
    }
};