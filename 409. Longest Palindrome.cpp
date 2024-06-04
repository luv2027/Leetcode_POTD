class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        int n = s.size();

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        int ans = 0;
        int odd = 0;
        for(auto x: mp){
            if(x.second%2 == 1){
                odd = 1;
                ans += (x.second - 1);
            }
            else{
                ans += x.second;
            }
        }

        if(odd){
            ans += 1;
        }

        return ans;
    }
};