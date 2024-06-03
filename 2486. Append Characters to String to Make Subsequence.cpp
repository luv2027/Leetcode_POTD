class Solution {
public:
    int appendCharacters(string s, string t) {
        int n = s.size();
        int m = t.size();
        int i = 0;
        int j = 0;  

        while(j<m && i<n){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        } 

        if(j != m){
            return (m - j); 
        }

        return 0;
    }
};