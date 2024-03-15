class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {        
        long long mul = 1;
        int n = nums.size();

        int f = 0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
                mul *= nums[i];
            }
            else{
                f ++;
            }
        }

        if(f > 1){
            for(int i=0; i<n; i++){
                ans.push_back(0);
            }
        }
        else if(f == 1){
            for(int i=0; i<n; i++){
                if(nums[i] == 0){
                    ans.push_back(mul);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                ans.push_back(mul/nums[i]);
            }
        }

        return ans;
    }
};