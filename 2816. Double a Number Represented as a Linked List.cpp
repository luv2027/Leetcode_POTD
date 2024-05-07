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
    ListNode* reverseList(ListNode *head){
        ListNode* prev = NULL;
        ListNode* curr = head, *next_node;

        while(curr != NULL){
            next_node = curr -> next;
            curr -> next = prev;

            prev = curr;
            curr = next_node;
        }
        return prev;
    }

    ListNode* doubleIt(ListNode* head) {
        ListNode* rev = reverseList(head);
        ListNode* temp = rev, *prev = NULL;

        int carry = 0;
        while(temp != NULL){
            int value = temp -> val;
            value *= 2;
            value += carry;

            if(value > 9){
                carry = 1;
            }
            else{
                carry = 0;
            }

            temp -> val = value%10;
            prev = temp;
            temp = temp -> next;
        }

        if(carry != 0){
            ListNode* extra_node = new ListNode(carry);
            prev -> next = extra_node;
        }

        ListNode* ans = reverseList(rev);
        return ans;
    }
};