class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = (long long)(n)*(n+1)/2;
        int maxi = INT_MIN;
        int c = 0;

        for(auto x:nums){
            maxi = max(maxi, x);
        }

        long long not_needed = 0;
        for(int right = 0; right<n; right++){
            if(nums[right] == maxi){
                c++;
            }

            while(c >= k){
                if(nums[left] == maxi){  
                    c--;
                }
                left++;
            }
            not_needed += (right-left+1);
        }
        
        return ans - not_needed;
    }
};