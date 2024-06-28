class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);

        int sz = roads.size();
        for(int i=0; i<sz; i++){
            degree[roads[i][0]]++;
            degree[roads[i][1]]++;
        }

        sort(degree.begin(), degree.end());
        long long ans = 0;
        for(int i=0; i<n; i++){
            ans += (degree[i] * (i + 1));
        }

        return ans;
    }
};