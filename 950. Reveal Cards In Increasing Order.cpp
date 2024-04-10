class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> odd;
        sort(deck.begin(), deck.end());
        deque<int> dq;
        reverse(deck.begin(), deck.end());
            
        for(int i=0; i<n; i++){
                if(dq.size() == 0){
                dq.push_back(deck[i]);
                }
                else{
                    int val = dq.back();
                    dq.pop_back();
                    dq.push_front(val);
                    dq.push_front(deck[i]);
                }
        }
    
        for(auto x: dq){
            odd.push_back(x);
        }

        return odd;
    }
};