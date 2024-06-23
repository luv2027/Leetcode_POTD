class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        multiset<int> s;

        int head = -1;
        int tail = 0;
        int ans = 1;

        while (tail < n) {
            while (head + 1 < n) {
                int new_mini = head >= tail ? min(*s.begin(), nums[head + 1]) : nums[head + 1];
                int new_maxi = head >= tail ? max(*s.rbegin(), nums[head + 1]) : nums[head + 1];

                if (abs(new_maxi - new_mini) <= limit) {
                    head++;
                    s.insert(nums[head]);
                } else {
                    break;
                }
            }

            ans = max(ans, head - tail + 1);

            if (tail > head) {
                tail++;
                head = tail - 1;
            } else {
                if (s.find(nums[tail]) != s.end()) {
                    s.erase(s.find(nums[tail]));
                } 
                tail++;
            }
        }
        return ans;
    }
};