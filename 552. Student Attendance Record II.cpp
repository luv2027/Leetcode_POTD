class Solution {
public:
    int mod = 1e9+7;
    int dp[100010][5][4];

    int rec(int index, int late, int ab){
        if(late < 3 && ab < 2 && index == 0){
            return 1;
        }

        if(dp[index][late][ab] != -1){
            return dp[index][late][ab];
        }

        long long ans = 0;
        ans = ans + rec(index-1, 0, ab)%mod;
        if(late+1 < 3){
            ans = ans + rec(index-1, late+1 , ab)%mod;
        }
        if(ab + 1 < 2){
            ans = ans + rec(index -1, 0, ab + 1)%mod;
        }
        ans %= mod;

        return dp[index][late][ab] = ans;
    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));

        return rec(n, 0, 0);
    }
};