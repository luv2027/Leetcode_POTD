class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans += 4;
                    if(i-1 >=0 && grid[i-1][j] == 1){
                        ans -= 1;
                    }
                    if(j-1 >=0 && grid[i][j-1] == 1){
                        ans -= 1;
                    }
                    if(i+1 <n && grid[i+1][j] == 1){
                        ans -= 1;
                    }
                    if(j+1 <m && grid[i][j+1] == 1){
                        ans -= 1;
                    }
                }
            }
        }

        return ans;
    }
};