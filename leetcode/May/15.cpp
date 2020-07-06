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
    ListNode* oddEvenList(ListNode* head) {
        if(head ==NULL) return head;
        ListNode * first = head;
        ListNode *second = first ->next;
        ListNode * tmp=second;
        ListNode * prev;
        while(second !=NULL) {
            //cout << first->val << " " << second->val << "++\n";
            first->next = second->next;
            prev = first;
            first = second->next;
            if(second->next){
                second->next = second->next->next;
                second = second->next;
            } 
            else{ second->next = NULL; second = NULL;}
        }
        if(first) first->next=tmp;
        else prev->next=tmp;
        return head;
        
    }
};
