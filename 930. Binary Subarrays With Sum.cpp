class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int s = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        freq[0] = 1;

        for(int i=0; i<n; i++){
            s += nums[i];

            if(freq.find(s - goal) != freq.end()){
                ans += freq[s - goal];
            }

            freq[s]++;
        }

        return ans;
    }
};