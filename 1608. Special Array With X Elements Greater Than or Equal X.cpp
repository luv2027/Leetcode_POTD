class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for(int i=0; i<=1000;  i++){
            auto LessThanIth = lower_bound(nums.begin(), nums.end(), i);
            int LessThan = LessThanIth - nums.begin();
            int GreaterThanEqualIth = n - LessThan;

            if(GreaterThanEqualIth == i){
                return i;
            }
        }

        return -1;
    }
};