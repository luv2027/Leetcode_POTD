class Solution {
public:
    int pivotInteger(int n) {
        for(int x=1; x<=n; x++){
            int s1 = x*(x+1)/2;
            int s2 = n*(n+1)/2 - (x-1)*x/2;
            if(s1 == s2){
                return x;
            }
        }
        return -1;
    }
};
