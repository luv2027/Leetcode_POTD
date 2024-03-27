class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int ans = 0;
        long long product = 1; 
        int n = nums.size();
        int left = 0;

        for (int right = 0; right < n; right++) {
            product *= nums[right];
            while (left < right && product >= k) {
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }

        return ans;
    }
};
