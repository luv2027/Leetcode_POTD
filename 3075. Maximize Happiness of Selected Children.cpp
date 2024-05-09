class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        int n = happiness.size();
        long long ans = 0;
        int c = 0;
        for(int i=n-1; i>=0; i--){
            ans = (long long)ans + max(0, (happiness[i] - c));
            c++;
            if(c == k){
                break;
            }
        }
        return ans;
    }
};