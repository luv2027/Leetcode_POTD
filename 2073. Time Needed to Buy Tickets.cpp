class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int, int>> q;
        int n = tickets.size();

        for(int i=0; i<n; i++){
            q.push({tickets[i], i});
        }

        int ans = 0;
        while(!q.empty()){
            int val = q.front().first;
            int ind = q.front().second;
            q.pop();
            val--;
            ans++;

            if(val == 0 && ind == k){
                break;
            }
            if(val != 0){
                q.push({val, ind});
            }
        }

        return ans;
    }
};