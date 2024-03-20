class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        
        for (int i = 0; i < a - 1; i++){
            curr = curr->next;
        }
        
        ListNode* start = curr; 
        
        for (int i = 0; i < b - a + 2; i++){
            curr = curr->next;
        }
        
        ListNode* end = curr; 
        
        start->next = list2;
    
        while (list2->next != NULL){
            list2 = list2->next;
        }
            
        list2->next = end;
        
        return list1;
    }
};
