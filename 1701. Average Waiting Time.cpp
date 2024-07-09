class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();

        long long sum = customers[0][0];
        sum += customers[0][1];
        long long avg_sum = customers[0][1];

        for(int i=1; i<n; i++){
            if(sum >= customers[i][0]){
                sum += customers[i][1];
                avg_sum += (sum - customers[i][0]);
            }
            else{
                sum = customers[i][0] + customers[i][1];
                avg_sum += customers[i][1];
            }
        }

        return avg_sum/double(n);
    }
};