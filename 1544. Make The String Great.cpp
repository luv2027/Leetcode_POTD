class Solution {
public:
    string makeGood(string s) {
        stack<char> stk;
        int n = s.size();
        for(int i=0; i<n; i++){
            if(!stk.empty()){
                char prev = stk.top();
                char curr = s[i];

                if(islower(prev) ^ islower(curr)){
                    if(toupper(prev) == s[i]  || tolower(prev) == s[i]){
                        stk.pop();
                    }
                    else{
                        stk.push(s[i]);
                    }
                }
                else{
                    stk.push(s[i]);
                }
            }
            else{
                stk.push(s[i]);
            }
        }

        string ans = "";
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};