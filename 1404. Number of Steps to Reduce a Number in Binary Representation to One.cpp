class Solution {
public:
    bool zero_found(string str){
        int sz = str.size();

        for(int i=0; i<sz; i++){
            if(str[i] == '0'){
                return true;
            }
        }
        return false;
    }

    string add_one(string st){
        int sz = st.size();

        string ans = "";
        ans += '1';
        for(int i=0; i<sz; i++){
            ans += '0';
        }

        return ans;
    }

    string between_zero(string st){
        int sz = st.size();
        int ind_zero = -1;
        for(int i=sz-1; i>=0; i--){
            if(st[i] == '0'){
                ind_zero = i;
                break;
            }
        }

        string ans = "";
        for(int i=0; i<ind_zero; i++){
            ans += st[i];
        }

        ans += '1';

        for(int i=ind_zero+1; i<sz; i++){
            ans += '0';
        }
        return ans;
    }

    int numSteps(string s) {
        int ans = 0;

        while(s.size() > 1){
            int len = s.size();
            int ind = len - 1;
            ans++;

            string inter = s;
            if(s[ind] == '0'){
                s = inter.substr(0, ind);
            }
            else{
                bool zero_present = zero_found(inter);
                if(zero_present){
                    s = between_zero(inter);
                }
                else{
                    s = add_one(inter);
                }
            }
        }
        return ans;
    }
};