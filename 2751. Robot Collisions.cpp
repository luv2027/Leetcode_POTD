class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
       int n = directions.size();
       vector<vector<int>> v(n); 

       for(int i=0; i<n; i++){
            int dir = (directions[i] == 'R') ? 1:0;
            v[i] = {positions[i], healths[i], dir} ;
       }

       sort(v.begin(), v.end());

       stack<vector<int>> stk; 

       for(int i=0; i<n; i++){
            if(!stk.empty()){
                int curr_pos = v[i][0];
                int curr_health = v[i][1];
                int direction = v[i][2];

                vector<int> arr = stk.top();
                int pos = arr[0];
                int prev_health = arr[1];
                int prev_dir = arr[2];

                if(direction == 1 && prev_dir == 0){
                    stk.push({curr_pos, curr_health, direction});
                }
                else if(direction == 0 && prev_dir == 1){
                    if(curr_health == prev_health){
                        stk.pop();
                    }
                    else if(curr_health < prev_health){
                        stk.pop();
                        stk.push({pos, prev_health - 1, prev_dir});
                    }
                    else{
                        while(!stk.empty() && stk.top()[1] < curr_health && stk.top()[2] != direction){
                            curr_health -= 1;
                            stk.pop();
                        }

                        if(!stk.empty() && stk.top()[1] > curr_health && stk.top()[2] != direction){
                            int prev_pos = stk.top()[0];
                            int val = stk.top()[1];
                            int where = stk.top()[2];

                            stk.pop();
                            stk.push({prev_pos, val-1, where});
                        }
                        else if(!stk.empty() && stk.top()[1] == curr_health && stk.top()[2] != direction){
                            stk.pop();
                        }
                        else{
                            stk.push({curr_pos, curr_health, direction});
                        }
                    }
                }
                else{
                    stk.push(v[i]);
                }
            }
            else{
                stk.push(v[i]);
            }
       }

       unordered_map<int, int> mp;

       while(!stk.empty()){
          vector<int> vec = stk.top();
          stk.pop();
          mp[vec[0]] = vec[1];
       }

       vector<int> ans;
       for(int i=0; i<positions.size(); i++){
            if(mp[positions[i]] != 0){
                ans.push_back(mp[positions[i]]);
            }
       }

       return ans;
    }
};