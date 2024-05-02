class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int, int>freq;
        int n = nums.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            if(nums[i] < 0){
                int pos = -nums[i];
                if(freq[pos] > 0){
                    ans = max(ans, pos);
                }
                freq[nums[i]]++;
            }
            else{
                int neg = -nums[i];
                if(freq[neg] > 0){
                    ans = max(ans, nums[i]);
                }
                freq[nums[i]]++;
            }
        }
        return ans;
    }
};