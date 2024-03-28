class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size();
        int left = 0;
        int maxi = 0;

        for(int right = 0; right<n; right++){
            mp[nums[right]]++;
            int curr_freq = mp[nums[right]];
            if(curr_freq > k){
                int konsa_banda = nums[right];
                while(true){
                    if(nums[left] == konsa_banda){
                        mp[nums[left]]--;
                        left++;
                        break;
                    }
                    mp[nums[left]]--;
                    left++;
                }
            }
            maxi = max(maxi, right-left+1);
        }
        return maxi;
    }
};