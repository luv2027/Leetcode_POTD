class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans;

        int n = grid.size();
        int m = grid[0].size();

        for(int i=0; i<n; i++){
            vector<int> a;
            for(int j=0; j<m; j++){
                
                int maxi = INT_MIN;
                if(i+2 >= n || j+2 >= m){
                    continue;
                }

                int limit_r = i+2;
                int limit_col = j+2;
                for(int row = i; row <= limit_r; row++){
                    for(int col=j; col <= limit_col; col++){
                        maxi = max(maxi, grid[row][col]);
                    }
                }
                a.push_back(maxi);
            }

            if(a.size() > 0){
                ans.push_back(a);
            }
        }
        
        return ans;
    }
};