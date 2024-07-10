class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int c = 0;

        for(int i=0; i<n; i++){
            string s = logs[i];
            char first_s = s[0];

            if(first_s == '.'){
                if(s[1] == '.'){
                    if(c > 0) c--;
                }
            }
            else{
                c++;
            }
        }

        return c;
    }
};