class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();

        int arr[26];
        for(int i=0; i<sz; i++){
            arr[tasks[i] - 'A']++;
        }

        int maxi = 0;
        for(int i=0; i<26; i++){
            if(arr[i] > maxi){
                maxi = arr[i];
            }
        }

        int val = maxi*(n+1);
        if(val <= sz){
            return sz;
        }

        int c = 0;
        for(int i=0; i<26; i++){
            if(arr[i] == maxi){
                c++;
            }
        }

        if(val - (n - (c-1)) <= sz){
            return sz;
        }

        return val - (n-(c-1));
    }
};