class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        string ans = words[0];
        sort(ans.begin(), ans.end());
        int n = words.size();

        for(int i=1; i<n; i++){
            string curr = words[i];
            sort(curr.begin(), curr.end());

            string common = "";
            int len = ans.size();
            int len2 = curr.size();
            int ith = 0;
            int jth = 0;
            while(ith < len && jth < len2){
                if(ans[ith] == curr[jth]){
                    common += ans[ith];
                    ith++;
                    jth++;
                }
                else if(ans[ith] > curr[jth]){
                    jth++;
                }
                else{
                    ith++;
                }
            }

            ans = common;
        }

        vector<string> sol;
        for(int i=0; i<ans.size(); i++){
            string c = "";
            c += ans[i]; 
            sol.push_back(c);
        }

        return sol;        
    }
};