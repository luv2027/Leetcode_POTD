class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long val = 0;

        for(int i=0; i<n; i++){
            val ^= nums[i];
        }

        long long rightmostOne = val& ~(val - 1);

        int a = 0;
        int b = 0;

        for(int i=0; i<n; i++){
            if(nums[i]&rightmostOne){
                a ^= nums[i];
            }
            else{
                b ^= nums[i];
            }
        }

        vector<int> ans = {a, b};
        return ans;
    }
};