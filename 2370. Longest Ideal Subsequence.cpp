class Solution {
public:
    int dp[100001][26];
    int n;
    string st;
    int k1;

    int rec(int level, int previous_letter){
        if(level == n){
            return 0;
        }

        if(dp[level][previous_letter] != -1){
            return dp[level][previous_letter];
        }

        int ans = 0;
        int order_alpha = st[level] - 'a';
        if(abs(order_alpha  - previous_letter) <= k1){
            ans = 1 + max(ans,rec(level+1, order_alpha));
        }
        ans = max(ans, rec(level + 1, previous_letter));

        return dp[level][previous_letter] = ans;
    }

    int longestIdealString(string s, int k) {
        n = s.size();
        st = s;
        k1 = k;
        memset(dp, -1, sizeof(dp));

        int len = 0;
        for(int i=0; i<n; i++){
            len = max(len, rec(i, s[i] - 'a'));
        }
        return len;
    }
};