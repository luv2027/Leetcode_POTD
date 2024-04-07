class Solution {
public:
    bool checkValidString(string s) {
        int o = 0, c = 0, st = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                o++;
            } else if (s[i] == ')') {
                c++;
            } else if (s[i] == '*') {
                st++;
            }
            
            if (c > o + st) {
                return false;
            }
        }
        
        o = 0;
        c = 0;
        st = 0;
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(') {
                o++;
            } else if (s[i] == ')') {
                c++;
            } else if (s[i] == '*') {
                st++;
            }
            
            if (o > c + st) {
                return false;
            }
        }
        
        return true;
    }
};