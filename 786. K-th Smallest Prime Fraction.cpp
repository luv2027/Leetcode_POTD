class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int, int>>>pq;

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                double value = arr[i]/(double)arr[j];

                pq.push({value, {arr[i], arr[j]}});
                
                if(pq.size() > k){
                    pq.pop();
                }
            }
        }

        vector<int> ans;
        ans.push_back(pq.top().second.first);
        ans.push_back(pq.top().second.second);
        return ans;
    }
};