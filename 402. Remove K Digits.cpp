class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.size();
        stack<char> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && k>0 && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        int m = ans.size();
        if(k > 0){
            if(k >= m){
                return "0";
            }
            ans = ans.erase(m-k);
        }

        int count_zero_front = 0;
        int ind = 0;
        while(ans[ind]== '0' && ind<ans.size()){
            count_zero_front++;
            ind++;
        }
        
        if(ind >= ans.size()){
            return "0";
        }

        ans = ans.substr(count_zero_front, ans.size() - count_zero_front); 
        
        if(ans.size()){
            return ans;
        }

        return "0";
    }
};