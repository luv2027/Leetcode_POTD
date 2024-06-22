class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int head = -1;
        int tail = 0;
        int o = 0;

        while(tail < n){
            while(head + 1 < n && o<k){
                head++;
                if(nums[head]%2 == 1){
                    o++;
                }
            }

            if(o == k){
                int temp_head = head + 1;
                while(temp_head < n && nums[temp_head]%2 == 0){
                    temp_head++;
                }
                ans += (temp_head - head);
            }

            if(tail > head){
                tail++;
                head = tail - 1;
            }
            else{
                if(nums[tail]%2 == 1){
                    o--;
                }
                tail++;
            }
        }

        return ans;
    }
};