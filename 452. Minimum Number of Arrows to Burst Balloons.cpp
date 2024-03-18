class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int n = points.size();

        if (n == 0) return 0;

        int ans = 1;
        int prevEnd = points[0][1];

        for (int i = 1; i < n; i++) {
            if (points[i][0] > prevEnd) {
                ans++;
                prevEnd = points[i][1];
            } else {
                prevEnd = min(prevEnd, points[i][1]);
            }
        }

        return ans;
    }
};
