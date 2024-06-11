class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        int n = arr1.size();

        for(int i=0; i<n; i++){
            freq[arr1[i]]++;
        }

        vector<int> ans;
        for(int i=0; i<arr2.size(); i++){
            int element = arr2[i];
            int frequency = freq[element];
            freq[element] = 0;
            while(frequency--){
                ans.push_back(element);
            }
        }

        for(int i=0; i<=1000; i++){
            if(freq[i] > 0){
                int kitni_baar = freq[i];
                while(kitni_baar--){
                    ans.push_back(i);
                }
            }
        }

        return ans;
    }
};