class Solution {
public:
    int dp[201][201];
    int n;
    vector<vector<int>>g;

    int rec(int i, int prev_col){
        if(i == n){
            return 0;
        }

        if(dp[i][prev_col] != 1e9){
            return dp[i][prev_col];
        }

        int ans = 1e9;
        for(int col=0; col<n; col++){
            if(col != prev_col){
                ans = min(ans, g[i][col] + rec(i+1, col));
            }
        }

        return dp[i][prev_col] = ans; 
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        if(n == 1){
            return grid[0][0];
        }

        g = grid;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = 1e9;
            }
        }

        int mini = INT_MAX;
        for(int col=0; col<n; col++){
            mini = min(mini, rec(0, col));
        }

        return mini;
    }
};