class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int mxl[n];
        int maxi =height[0];
        mxl[0] = maxi;

        for(int i=1; i<n; i++){
            maxi = max(maxi, height[i]);
            mxl[i] = maxi;
        }

        int mxr[n];
        maxi = height[n-1];
        mxr[n-1] = maxi;

        for(int i=n-2; i>=0; i--){
            maxi = max(maxi, height[i]);
            mxr[i] = maxi;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = ans + ((min(mxl[i], mxr[i])) - height[i]);
        }
        return ans;
    }
};