class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int c1 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 1) c1++;
        }

        if(c1 == 0 || c1 == 1 || c1 == n) return 0;

        vector<int> v(2*n);
        for(int i=0; i<n; i++){
            v[i] = nums[i];
            v[i+n] = nums[i];
        }

        int c = 0;
        int c0 = 0;
        int k = c1;
        int mini = n;
        int i = 0;

        for(i=0; i<k; i++){
            if(v[i] == 0)c0++;
        }

        mini = min(mini, c0);

        for(i=k; i<2*n; i++){
            if(v[i-k] == 0)c0--;
            if(v[i] == 0)c0++;
            mini = min(mini, c0);
        }

        return mini;
    }
};