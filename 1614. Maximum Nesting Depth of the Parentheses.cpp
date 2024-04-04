class Solution {
public:
    int maxDepth(string s) {
        int n = s.size();
        int c = 0;
        int max_c = 0;

        for(auto x: s){
            if(x == '('){
                c++;
            }
            else if(x == ')'){
                c--;
            }
            max_c = max(max_c, c);
        }

        return max_c;
    }
};