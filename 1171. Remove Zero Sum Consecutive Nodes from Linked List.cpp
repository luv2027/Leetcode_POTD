class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;
        
        unordered_map<int, ListNode*> prefixSum;
        int sum = 0;
        for (ListNode* current = temp; current != nullptr; current = current->next) {
            sum += current->val;
            prefixSum[sum] = current;
        }
        
        sum = 0;
        for (ListNode* current = temp; current != nullptr; current = current->next) {
            sum += current->val;
            current->next = prefixSum[sum]->next;
        }
        
        return temp->next;
    }
};
