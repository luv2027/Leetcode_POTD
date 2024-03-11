class Solution {
public:
    string customSortString(string order, string s) {
        int n = s.size();

        unordered_map<char, int> mp;

        for(auto x: s){
            mp[x]++;
        }

        string ans = "";

        for(int i=0; i<order.size(); i++){
            if(mp.find(order[i]) != mp.end()){
                int times = mp[order[i]];
                while(times--){
                    ans += order[i];
                }
                mp.erase(order[i]);
            }
        }

        for(auto x: mp){
            char ch = x.first;
            int how_times = x.second;
            while(how_times--){
                ans += ch;
            }
        }

        return ans;
    }
};