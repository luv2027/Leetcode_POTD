using p = pair<int, int>;

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<p, vector<p>, greater<p>> minh;
        priority_queue<int> maxh;

        int n = profits.size();

        for(int i=0; i<n; i++){
            if(capital[i] <= w){
                maxh.push(profits[i]);
            }
            else{
                minh.push({capital[i], profits[i]});
            }
        }

        while(k--){
            if(!maxh.empty()){
                w += maxh.top();
                maxh.pop();
            }

            while(!minh.empty() && minh.top().first <= w){
                maxh.push(minh.top().second);
                minh.pop();
            }
        }

        return w;
    }
};