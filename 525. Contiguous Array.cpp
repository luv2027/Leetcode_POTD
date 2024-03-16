class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        int pre_fix = 0;
        int n = nums.size();
        mp[0] = -1;

        for(int i=0; i<n; i++){
            pre_fix += (nums[i] == 1? 1 : -1);

            if(mp.find(pre_fix) != mp.end()){
                ans = max(ans, i - mp[pre_fix]);
            }
            else{
                mp[pre_fix] = i;
            }
        }

        return ans;
    }
};