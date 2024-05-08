class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int>a = score;
        sort(a.begin(), a.end());

        int n = score.size();
        vector<string> ans;

        for(int i=0; i<n; i++){
            int ind = lower_bound(a.begin(), a.end(), score[i]) - a.begin();
            ind++;
            ind = n - ind;
            if(ind == 0){
                ans.push_back("Gold Medal");
            }
            else if(ind == 1){
                ans.push_back("Silver Medal");
            }
            else if(ind == 2){
                ans.push_back("Bronze Medal");
            }
            else{
                ans.push_back(to_string(ind+1));
            }
        }
        return ans;
    }
};