class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> dis;
        vector<int> d;

        ListNode* temp = head;
        int c = 1;
        int p = temp -> val; 
        temp = temp -> next;

        while(temp != NULL){
            int nx = -1;
            if(temp -> next != NULL){
                nx = temp -> next -> val;
            }

            int curr = temp -> val;

            if(nx != -1 && curr > p && curr > nx){
                d.push_back(c);
            }
            else if(nx != -1 && curr < p && curr < nx){
                d.push_back(c);
            }

            c++;
            p = curr;
            temp = temp -> next;
        }

        if(d.size() <= 1) return {-1, -1};

        int mini = INT_MAX;

        for(int i=0; i<d.size()-1; i++){
            mini = min(mini, d[i+1] - d[i]);
        }

        int maxi = d[d.size()-1] - d[0];
        return {mini, maxi};
    }
};