class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<pair<char, int>> stk;
        int n = s.size();
        int c = 0;

        for(int i=0; i<n; i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                ans += s[i];
            }
            else if(s[i] == '('){
                stk.push({'(', i-c});
            }
            else{
                if(!stk.empty()){
                    auto p = stk.top();
                    int index = p.second;
                    stk.pop();
                    int before_him = stk.size();
                    ans.insert(index - before_him, "(");
                    ans += s[i];
                }
                else{
                    c++;
                }
            }
        }
        return ans; 
    }
};