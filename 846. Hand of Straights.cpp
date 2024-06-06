class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n% groupSize != 0){
            return false;
        }

        map<int, int> mp;
        for(auto x: hand){
            mp[x]++;
        }

        for(auto x: mp){
            int element = x.first;
            int freq = x.second;
            while(freq--){
                for(int i=1; i<groupSize; i++){
                    if(mp.find(element + i) == mp.end()){
                        return false;
                    }
                    else{
                        mp[element + i]--;
                        if(mp[element + i] == 0){
                            mp.erase(element + i);
                        }
                    }
                }
            }
            mp.erase(element);
        }

        return true;
    }
};