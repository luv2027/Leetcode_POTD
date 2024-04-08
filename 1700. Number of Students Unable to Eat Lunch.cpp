class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int o = 0, z = 0;
        for(int i=0; i<n; i++){
            if(students[i] == 1){
                o++;
            }
            else{
                z++;
            }
        }

        int j = 0;
        while(j < n){
            if(sandwiches[j] == 1 && o>0){
                o--;
            }
            else if(sandwiches[j] == 0 && z > 0){
                z--;
            }
            else{
                break;
            }
            j++;
        }

        return n-j;
    }
};