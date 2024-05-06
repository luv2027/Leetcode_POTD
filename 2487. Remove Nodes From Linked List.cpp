/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp = head;
        vector<pair<int, bool>> v;

        while(temp != NULL){
            int value = temp -> val;
            temp = temp -> next;
            v.push_back({value, true});
        }

        int n = v.size();
        int maxi = INT_MIN;
        for(int i=n-1; i>=0; i--){
            if(v[i].first > maxi){
                maxi = v[i].first;
            }
            else if(v[i].first == maxi){
                continue;
            }
            else{
                v[i].second = false;
            }
        }

        ListNode* ans_head = new ListNode(NULL);
        temp = ans_head;
        for(int i=0; i<n; i++){
            if(v[i].second == true){
                ListNode* node = new ListNode(v[i].first);
                temp -> next = node;
                temp = temp -> next;
            }
        }

        return ans_head -> next;
    }
};