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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* t = dummy;
        ListNode* forward = head -> next;
        ListNode* backward = head;

        while(backward != NULL){
            int s = 0;
            while(forward != NULL && forward -> val != 0){
                s += (forward -> val);
                forward = forward -> next;
            }

            ListNode* new_node = new ListNode(s);
            t -> next = new_node;
            t = new_node;

            forward = forward -> next;
            backward = forward;
        }

        return dummy -> next;
    }
};